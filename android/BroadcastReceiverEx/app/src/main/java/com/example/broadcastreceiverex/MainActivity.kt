package com.example.broadcastreceiverex

import android.content.IntentFilter
import android.os.Bundle
//import android.util.Log
import android.widget.EditText
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.content.ContextCompat
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.google.android.gms.auth.api.phone.SmsRetriever

class MainActivity : AppCompatActivity() {

    private lateinit var smsReceiver: MySMSBroadcastReceiver
    private lateinit var otpInputField: EditText

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
                val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
                v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
                insets
        }
//        val appSignatureHelper = AppSignatureHelper(this)
//        Log.d("OTP_HASH", "My App Hash is: ${appSignatureHelper.appSignatures[0]}")

        otpInputField = findViewById(R.id.otpInputField)
        smsReceiver = MySMSBroadcastReceiver()

        smsReceiver.otpListener = {
            otp -> otpInputField.setText(otp)
        }

        val client = SmsRetriever.getClient(this)
        client.startSmsRetriever()
//        val task = client.startSmsRetriever()

//        task.addOnSuccessListener {
//            // The OS is now listening for the SMS!
//            Log.d("OTP_LISTEN", "SMS Retriever started successfully")
//        }

//        task.addOnFailureListener {
//            // Something went wrong
//            Log.e("OTP_LISTEN", "SMS Retriever failed to start")
//        }
    }

    override fun onResume() {
        super.onResume()
        // Register receiver when the screen comes into the foreground
        val intentFilter = IntentFilter(SmsRetriever.SMS_RETRIEVED_ACTION)
        ContextCompat.registerReceiver(
            this,
            smsReceiver,
            intentFilter,
            SmsRetriever.SEND_PERMISSION,
            null,
            ContextCompat.RECEIVER_EXPORTED
        )
    }

    override fun onPause() {
        super.onPause()
        // Unregister receiver when the screen goes into the background
        unregisterReceiver(smsReceiver)
    }
}