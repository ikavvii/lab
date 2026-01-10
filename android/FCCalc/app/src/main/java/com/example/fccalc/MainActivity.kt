package com.example.fccalc

import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
        val inputFahrenheit = findViewById<EditText>(R.id.editTextText)
        val displayCelsius = findViewById<EditText>(R.id.editTextText2)

        val convertButton = findViewById<Button>(R.id.button)
        convertButton.setOnClickListener {
            val tF: Double = (inputFahrenheit.text.toString().toDoubleOrNull() ?: 0) as Double
            val tC: Double = (tF - 32)* 5 / 9
            displayCelsius.setText("$tC")
        }

        val clearButton = findViewById<Button>(R.id.button2)
        clearButton.setOnClickListener {
            inputFahrenheit.setText("")
            displayCelsius.setText("")
        }

    }
}