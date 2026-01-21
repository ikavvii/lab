package com.example.ratingbar

import android.os.Bundle
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class ResultActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_result)

        val tvFeedbackResult = findViewById<TextView>(R.id.tvFeedbackResult)
        val feedback = intent.getStringExtra("EXTRA_FEEDBACK")
        tvFeedbackResult.text = feedback
    }
}
