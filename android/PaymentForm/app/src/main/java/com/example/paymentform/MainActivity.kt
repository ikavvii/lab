package com.example.paymentform

import android.content.Intent
import android.os.Bundle
import android.widget.*
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // --- Views ---
        val paymentTypeSpinner = findViewById<Spinner>(R.id.spinner2)
        val stateSpinner = findViewById<Spinner>(R.id.spinner4)
        val countrySpinner = findViewById<Spinner>(R.id.spinner3)

        val cardNumber = findViewById<EditText>(R.id.editTextText)
        val expiryDate = findViewById<EditText>(R.id.editTextDate)
        val cvv = findViewById<EditText>(R.id.editTextNumberPassword)

        val address = findViewById<EditText>(R.id.editTextText2)
        val city = findViewById<EditText>(R.id.editTextText3)
        val zipCode = findViewById<EditText>(R.id.editTextText4)

        val submitButton = findViewById<Button>(R.id.button)

        // --- Spinner Data ---
        setupSpinner(
            paymentTypeSpinner,
            listOf("Select Card Type", "Visa", "MasterCard", "RuPay")
        )

        setupSpinner(
            stateSpinner,
            listOf("Select State", "Tamil Nadu", "Karnataka", "Kerala", "Delhi")
        )

        setupSpinner(
            countrySpinner,
            listOf("Select Country", "India", "USA", "UK")
        )

        // --- Button Click ---
        submitButton.setOnClickListener {

            val card = cardNumber.text.toString()
            val securityCode = cvv.text.toString()

            if (card.length != 16) {
                cardNumber.error = "Enter valid 16-digit card number"
                return@setOnClickListener
            }

            if (securityCode.length < 3) {
                cvv.error = "Invalid CVV"
                return@setOnClickListener
            }

            Toast.makeText(
                this,
                "Payment Submitted Successfully",
                Toast.LENGTH_LONG
            ).show()

            val intent = Intent(this, MainActivity2::class.java)

            intent.putExtra("CARD_TYPE", paymentTypeSpinner.selectedItem.toString())
            intent.putExtra("CARD_NUMBER", cardNumber.text.toString())
            intent.putExtra("EXPIRY", expiryDate.text.toString())
            intent.putExtra("CVV", cvv.text.toString())
            intent.putExtra("ADDRESS", address.text.toString())
            intent.putExtra("CITY", city.text.toString())
            intent.putExtra("STATE", stateSpinner.selectedItem.toString())
            intent.putExtra("ZIP", zipCode.text.toString())
            intent.putExtra("COUNTRY", countrySpinner.selectedItem.toString())

            startActivity(intent)
        }
    }

    private fun setupSpinner(spinner: Spinner, items: List<String>) {
        val adapter = ArrayAdapter(
            this,
            android.R.layout.simple_spinner_dropdown_item,
            items
        )
        spinner.adapter = adapter
    }
}