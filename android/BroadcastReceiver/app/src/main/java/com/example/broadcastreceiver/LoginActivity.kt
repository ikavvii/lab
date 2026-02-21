package com.example.broadcastreceiver

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import androidx.appcompat.app.AppCompatActivity
import com.google.android.gms.auth.api.phone.SmsRetriever

class LoginActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_login)

        val etPhone = findViewById<EditText>(R.id.et_phone)
        val getOtpButton = findViewById<Button>(R.id.btn_get_otp)

        getOtpButton.setOnClickListener {
            val phoneNumber = etPhone.text.toString()
            // 1. Tell Android to start watching for an OTP SMS.
            SmsRetriever.getClient(this).startSmsUserConsent(null)

            // 2. Move the user to the OTP input screen
            val intent = Intent(this, OtpInputActivity::class.java)
            intent.putExtra("mobile_number", phoneNumber)
            startActivity(intent)
        }
    }
}