package com.example.ratingbar

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.RatingBar
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val ratingBar = findViewById<RatingBar>(R.id.ratingBar)
        val tvRatingStatus = findViewById<TextView>(R.id.tvRatingStatus)
        val etFeedback = findViewById<EditText>(R.id.etFeedback)
        val btnSendFeedback = findViewById<Button>(R.id.btnSendFeedback)

        ratingBar.onRatingBarChangeListener = RatingBar.OnRatingBarChangeListener { _, rating, _ ->
            val message = when (rating.toInt()) {
                5 -> "Awesome. I love it"
                4 -> "Good. Enjoyed it"
                3 -> "Satisfied."
                2 -> "Not good. Need improvement"
                1 -> "Disappointed. Very poor"
                else -> ""
            }
            tvRatingStatus.text = message
        }

        btnSendFeedback.setOnClickListener {
            val feedback = etFeedback.text.toString().trim()
            if (feedback.isEmpty()) {
                etFeedback.error = "Message is required"
            } else {
                val intent = Intent(this, ResultActivity::class.java)
                intent.putExtra("EXTRA_FEEDBACK", feedback)
                startActivity(intent)
            }
        }
    }
}
