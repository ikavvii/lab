package com.example.payments

import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.EditText
import androidx.fragment.app.Fragment
import androidx.fragment.app.activityViewModels

class PaymentFragment : Fragment(R.layout.fragment_payment) {
    private val sharedViewModel: RegistrationViewModel by activityViewModels()

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        val etCard = view.findViewById<EditText>(R.id.etCardNumber)
        val btnNext = view.findViewById<Button>(R.id.btnNext3)

        btnNext.setOnClickListener {
            sharedViewModel.cardNumber = etCard.text.toString()

            parentFragmentManager.beginTransaction()
                .replace(R.id.fragmentContainer, ConfirmFragment())
                .addToBackStack(null)
                .commit()
        }
    }
}