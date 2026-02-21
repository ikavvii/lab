package com.example.broadcastreceiverex

import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.util.Log
import com.google.android.gms.auth.api.phone.SmsRetriever
import com.google.android.gms.common.api.CommonStatusCodes
import com.google.android.gms.common.api.Status

class MySMSBroadcastReceiver : BroadcastReceiver() {

    // We can use an interface to pass the OTP back to your Activity
    var otpListener: ((String) -> Unit)? = null

    override fun onReceive(context: Context, intent: Intent) {
        if (SmsRetriever.SMS_RETRIEVED_ACTION == intent.action) {

            // Use getParcelableExtra instead of generic get()
            @Suppress("DEPRECATION")
            val status = intent.getParcelableExtra<Status>(SmsRetriever.EXTRA_STATUS)

            when (status?.statusCode) {
                CommonStatusCodes.SUCCESS -> {
                    // Use getStringExtra for the message
                    val message = intent.getStringExtra(SmsRetriever.EXTRA_SMS_MESSAGE)

                    if (message != null) {
                        Log.d("OTP_RECEIVER", "Full Message: $message")

                        // Search the message for exactly 6 digits in a row
                        val extractedOtp = Regex("\\d{6}").find(message)?.value

                        if (extractedOtp != null) {
                            Log.d("OTP_RECEIVER", "Extracted OTP: $extractedOtp")
                            // Send the 6 digits back to our Activity
                            otpListener?.invoke(extractedOtp)
                        }
                    }
                }
                CommonStatusCodes.TIMEOUT -> {
                    Log.d("OTP_RECEIVER", "Timeout")
                }
            }
        }
    }
}