package com.example.paymentform

import android.os.Bundle
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class MainActivity2 : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main2)

        val tvResult = findViewById<TextView>(R.id.tvResult)

        // Receive data from Intent
        val cardType = intent.getStringExtra("CARD_TYPE")
        val cardNumber = intent.getStringExtra("CARD_NUMBER")
        val expiry = intent.getStringExtra("EXPIRY")
        val cvv = intent.getStringExtra("CVV")
        val address = intent.getStringExtra("ADDRESS")
        val city = intent.getStringExtra("CITY")
        val state = intent.getStringExtra("STATE")
        val zip = intent.getStringExtra("ZIP")
        val country = intent.getStringExtra("COUNTRY")

        tvResult.text = getString(
            R.string.card_type_card_number_expiry_date_cvv_address_city_state_zip_country,
            cardType,
            cardNumber,
            expiry,
            cvv,
            address,
            city,
            state,
            zip,
            country
        ).trimIndent()
    }
}