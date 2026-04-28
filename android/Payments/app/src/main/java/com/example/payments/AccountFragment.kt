package com.example.payments

import android.os.Bundle
import android.util.Patterns
import android.view.View
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import androidx.fragment.app.Fragment
import androidx.fragment.app.activityViewModels

class AccountFragment : Fragment(R.layout.fragment_account) {
    private val sharedViewModel: RegistrationViewModel by activityViewModels()

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        val etEmail = view.findViewById<EditText>(R.id.etEmail)
        val etUsername = view.findViewById<EditText>(R.id.etUsername)
        val etPassword = view.findViewById<EditText>(R.id.etPassword)
        val etConfirmPassword = view.findViewById<EditText>(R.id.etConfirmPassword)
        val btnNext = view.findViewById<Button>(R.id.btnNext1)
        val tvViewRecords = view.findViewById<TextView>(R.id.tvViewRecords)

        tvViewRecords.setOnClickListener {
            parentFragmentManager.beginTransaction()
                .replace(R.id.fragmentContainer, DisplayFragment())
                .addToBackStack(null)
                .commit()
        }

        btnNext.setOnClickListener {
            val email = etEmail.text.toString()
            val pass = etPassword.text.toString()
            val confirmPass = etConfirmPassword.text.toString()

            if (!Patterns.EMAIL_ADDRESS.matcher(email).matches()) {
                etEmail.error = "Invalid Email"
                return@setOnClickListener
            }
            if (pass.isEmpty() || pass != confirmPass) {
                etConfirmPassword.error = "Passwords do not match"
                return@setOnClickListener
            }

            sharedViewModel.email = email
            sharedViewModel.username = etUsername.text.toString()
            sharedViewModel.password = pass

            parentFragmentManager.beginTransaction()
                .replace(R.id.fragmentContainer, PersonalFragment())
                .addToBackStack(null)
                .commit()
        }
    }
}