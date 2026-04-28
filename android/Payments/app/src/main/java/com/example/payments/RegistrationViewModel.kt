package com.example.payments

import androidx.lifecycle.ViewModel

class RegistrationViewModel : ViewModel() {
    // Step 1
    var email = ""
    var username = ""
    var password = ""

    // Step 2
    var firstName = ""
    var phone = ""

    // Step 3
    var cardNumber = ""
}