package com.example.fccalc

import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.core.widget.doOnTextChanged
import java.util.Locale

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
        val inputCelsius = findViewById<EditText>(R.id.editTextText2)

        inputFahrenheit.doOnTextChanged { text, _, _, _ ->
            if (inputFahrenheit.hasFocus()) {
                val tF = text.toString().toDoubleOrNull()
                if (tF != null) {
                    val tC = (tF - 32) * 5 / 9
                    inputCelsius.setText(String.format(Locale.getDefault(), "%.2f", tC))
                } else {
                    inputCelsius.setText("")
                }
            }
        }

        inputCelsius.doOnTextChanged { text, _, _, _ ->
            if (inputCelsius.hasFocus()) {
                val tC = text.toString().toDoubleOrNull()
                if (tC != null) {
                    val tF = (tC * 9 / 5) + 32
                    inputFahrenheit.setText(String.format(Locale.getDefault(), "%.2f", tF))
                } else {
                    inputFahrenheit.setText("")
                }
            }
        }

        val convertButton = findViewById<Button>(R.id.button)
        convertButton.setOnClickListener {
            val fValue = inputFahrenheit.text.toString()
            val cValue = inputCelsius.text.toString()

            if (fValue.isNotEmpty() && cValue.isNotEmpty()) {
                Toast.makeText(this, "$fValue°F is $cValue°C", Toast.LENGTH_SHORT).show()
            } else {
                Toast.makeText(this, "Please enter a value to convert", Toast.LENGTH_SHORT).show()
            }
        }

        val clearButton = findViewById<Button>(R.id.button2)
        clearButton.setOnClickListener {
            inputFahrenheit.setText("")
            inputCelsius.setText("")
        }
    }
}