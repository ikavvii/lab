package com.example.mocktest1

import android.content.Intent
import android.net.Uri
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity

class WhatsappSend : AppCompatActivity() {

    private lateinit var phoneEditText: EditText
    private lateinit var messageEditText: EditText
    private lateinit var sendButton: Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_whatsapp_send)

        phoneEditText = findViewById(R.id.editTextPhone)
        messageEditText = findViewById(R.id.editTextTextMultiLine)
        sendButton = findViewById(R.id.button)

        sendButton.setOnClickListener {
            val phoneNumber = phoneEditText.text.toString().trim()
            val message = messageEditText.text.toString().trim()

            // 1. Validation: Fields cannot be empty
            if (phoneNumber.isEmpty()) {
                phoneEditText.error = "Phone number is required"
                return@setOnClickListener
            }

            // Allow basic phone length validation (e.g., at least 10 digits)
            if (phoneNumber.length < 10) {
                phoneEditText.error = "Enter a valid phone number"
                return@setOnClickListener
            }

            if (message.isEmpty()) {
                messageEditText.error = "Message is required"
                return@setOnClickListener
            }

            // 2. Validation: Message cannot be more than 200 words
            val wordCount = message.split("\\s+".toRegex()).size
            if (wordCount > 200) {
                messageEditText.error = "Message exceeds 200 words. Current: $wordCount"
                Toast.makeText(this, "Message is too long ($wordCount/200 words)", Toast.LENGTH_LONG).show()
                return@setOnClickListener
            }

            // 3. Open WhatsApp
            openWhatsApp(phoneNumber, message)
        }
    }

    private fun openWhatsApp(phoneNumber: String, message: String) {
        try {
            // Using the API format for broad device compatibility
            val url = "https://api.whatsapp.com/send?phone=$phoneNumber&text=${Uri.encode(message)}"
            val intent = Intent(Intent.ACTION_VIEW)
            intent.data = Uri.parse(url)
            intent.setPackage("com.whatsapp")
            startActivity(intent)
        } catch (e: Exception) {
            // Fallback if the official package is not found
            Toast.makeText(this, "WhatsApp app not found. Opening in browser.", Toast.LENGTH_SHORT).show()
            val fallbackIntent = Intent(Intent.ACTION_VIEW, Uri.parse("https://api.whatsapp.com/send?phone=$phoneNumber&text=${Uri.encode(message)}"))
            startActivity(fallbackIntent)
        }
    }
}