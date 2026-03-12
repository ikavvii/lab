package com.example.email // Replace with your actual package name

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.core.net.toUri

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // 1. Find the views by their IDs from your XML layout
        val toEditText = findViewById<EditText>(R.id.editText1)
        val subjectEditText = findViewById<EditText>(R.id.editText2)
        val bodyEditText = findViewById<EditText>(R.id.editText3)
        val sendButton = findViewById<Button>(R.id.button)

        // 2. Set up the click listener for the Send button
        sendButton.setOnClickListener {
            val recipient = toEditText.text.toString().trim()
            val subject = subjectEditText.text.toString().trim()
            val message = bodyEditText.text.toString().trim()

            // Optional: Basic validation to ensure an email address is entered
            if (recipient.isEmpty()) {
                Toast.makeText(this, "Please enter a recipient email", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }

            // 3. Trigger the email intent
            sendEmail(recipient, subject, message)
        }
    }

    private fun sendEmail(recipient: String, subject: String, message: String) {
        // ACTION_SENDTO ensures only email apps resolve this intent
        val intent = Intent(Intent.ACTION_SENDTO).apply {
            data = "mailto:".toUri()
            putExtra(Intent.EXTRA_EMAIL, arrayOf(recipient))
            putExtra(Intent.EXTRA_SUBJECT, subject)
            putExtra(Intent.EXTRA_TEXT, message)
        }

        try {
            // Open an app chooser so the user can select their preferred email app (Gmail, Outlook, etc.)
            startActivity(Intent.createChooser(intent, "Choose an Email client:"))
        } catch (_: Exception) {
            Toast.makeText(this, "No email clients installed.", Toast.LENGTH_SHORT).show()
        }
    }
}