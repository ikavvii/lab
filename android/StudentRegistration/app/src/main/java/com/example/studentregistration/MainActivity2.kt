package com.example.studentregistration

import android.os.Bundle
import android.widget.EditText
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity2 : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main2)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        val name = intent.getStringExtra("name")
        val roll = intent.getStringExtra("roll")
        val gender = intent.getStringExtra("gender")
        val hobbies = intent.getStringExtra("hobbies")
        val programme = intent.getStringExtra("programme")
        val dob = intent.getStringExtra("dob")

        val form = findViewById<TextView>(R.id.result)

        // Inside MainActivity2 onCreate
        val formData = """
            学 Student Profile 学
            ---------------------
            Name:      $name
            Roll No:   $roll
            Gender:    $gender
            DOB:       $dob
            Program:   $programme
            Hobbies:   $hobbies
        """.trimIndent()

        form.text = formData
    }
}