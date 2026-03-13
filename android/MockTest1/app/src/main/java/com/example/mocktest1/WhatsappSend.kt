package com.example.mocktest1

import android.content.Intent
import android.net.Uri
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class WhatsappSend : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_whatsapp_send)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        val phone = findViewById<EditText>(R.id.editTextPhone)
        val message = findViewById<EditText>(R.id.editTextTextMultiLine)

        val sendButton = findViewById<Button>(R.id.button)

        sendButton.setOnClickListener {
            val phoneNumber = phone.text.toString().trim()
            val messageText = message.text.toString().trim()

            if (phoneNumber.isNotEmpty() && messageText.isNotEmpty()) {
                openWhatsapp(phoneNumber, messageText)
            } else {
                Toast.makeText(this, "Please enter a phone number and message", Toast.LENGTH_SHORT).show()
            }
        }
    }

    private fun openWhatsapp(phone: String, message: String) {

            val url = "https://api.whatsapp.com/send?phone=$phone&text=${Uri.encode(message)}"
            val intent = Intent(Intent.ACTION_VIEW).apply {
                data = Uri.parse(url)
            }

            startActivity(intent)

    }
}