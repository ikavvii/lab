package com.example.broadcastreceiver

import android.content.ActivityNotFoundException
import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.content.IntentFilter
import android.os.Bundle
import android.util.Log
import android.widget.Button
import android.widget.EditText
import android.widget.Toast
import androidx.activity.result.contract.ActivityResultContracts
import androidx.appcompat.app.AppCompatActivity
import androidx.core.content.ContextCompat
import androidx.core.os.BundleCompat
import com.google.android.gms.auth.api.phone.SmsRetriever
import com.google.android.gms.common.api.CommonStatusCodes
import com.google.android.gms.common.api.Status

class OtpInputActivity : AppCompatActivity() {

    private lateinit var etOtp: EditText
    private lateinit var btnResend: Button
    private lateinit var btnVerify: Button
    private var mobileNumber: String? = null

    private val smsConsentLauncher = registerForActivityResult(ActivityResultContracts.StartActivityForResult()) { result ->
        if (result.resultCode == RESULT_OK && result.data != null) {
            val message = result.data?.getStringExtra(SmsRetriever.EXTRA_SMS_MESSAGE)
            message?.let {
                etOtp.setText(parseOtp(it))
            }
        }
    }

    private val smsVerificationReceiver = object : BroadcastReceiver() {
        override fun onReceive(context: Context, intent: Intent) {
            if (SmsRetriever.SMS_RETRIEVED_ACTION == intent.action) {
                val extras = intent.extras
                val smsRetrieverStatus = extras?.let {
                    BundleCompat.getParcelable(it, SmsRetriever.EXTRA_STATUS, Status::class.java)
                }

                when (smsRetrieverStatus?.statusCode) {
                    CommonStatusCodes.SUCCESS -> {
                        val consentIntent = extras.let {
                            BundleCompat.getParcelable(it, SmsRetriever.EXTRA_CONSENT_INTENT, Intent::class.java)
                        }
                        try {
                            consentIntent?.let { smsConsentLauncher.launch(it) }
                        } catch (e: ActivityNotFoundException) {
                            Log.e("OtpInputActivity", "Consent Activity not found", e)
                        }
                    }
                    CommonStatusCodes.TIMEOUT -> {
                        Log.d("OtpInputActivity", "SMS Retriever timeout")
                    }
                }
            }
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_otp_input)

        mobileNumber = intent.getStringExtra("mobile_number")
        etOtp = findViewById(R.id.et_otp)
        btnResend = findViewById(R.id.btn_resend_otp)
        btnVerify = findViewById(R.id.btn_verify_otp)

        btnResend.setOnClickListener {
            resendOtp()
        }

        btnVerify.setOnClickListener {
            verifyOtp()
        }

        registerSmsReceiver()
        startSmsListener()
    }

    private fun verifyOtp() {
        val otp = etOtp.text.toString()
        if (otp.length in 4..6) {
            val intent = Intent(this, MainActivity::class.java)
            intent.putExtra("mobile_number", mobileNumber)
            startActivity(intent)
            finish()
        } else {
            Toast.makeText(this, "Please enter a valid OTP", Toast.LENGTH_SHORT).show()
        }
    }

    private fun registerSmsReceiver() {
        val intentFilter = IntentFilter(SmsRetriever.SMS_RETRIEVED_ACTION)
        ContextCompat.registerReceiver(
            this,
            smsVerificationReceiver,
            intentFilter,
            SmsRetriever.SEND_PERMISSION,
            null,
            ContextCompat.RECEIVER_EXPORTED
        )
    }

    private fun startSmsListener() {
        SmsRetriever.getClient(this).startSmsUserConsent(null)
            .addOnSuccessListener {
                Log.d("OtpInputActivity", "Successfully started SMS listener")
            }
            .addOnFailureListener {
                Log.e("OtpInputActivity", "Failed to start SMS listener", it)
            }
    }

    private fun resendOtp() {
        etOtp.text.clear()
        startSmsListener()
        Toast.makeText(this, "OTP Resent. Waiting for SMS...", Toast.LENGTH_SHORT).show()
    }

    private fun parseOtp(message: String): String {
        val otpPattern = "\\d{4,6}".toRegex()
        return otpPattern.find(message)?.value ?: ""
    }

    override fun onDestroy() {
        super.onDestroy()
        try {
            unregisterReceiver(smsVerificationReceiver)
        } catch (_: Exception) {
            // Receiver already unregistered
        }
    }
}
