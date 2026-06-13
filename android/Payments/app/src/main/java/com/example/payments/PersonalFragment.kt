package com.example.payments

import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.EditText
import androidx.fragment.app.Fragment
import androidx.fragment.app.activityViewModels

class PersonalFragment : Fragment(R.layout.fragment_personal) {
    private val sharedViewModel: RegistrationViewModel by activityViewModels()

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        val etFirstName = view.findViewById<EditText>(R.id.etFirstName)
        val etPhone = view.findViewById<EditText>(R.id.etPhone)
        val btnNext = view.findViewById<Button>(R.id.btnNext2)

        btnNext.setOnClickListener {
            sharedViewModel.firstName = etFirstName.text.toString()
            sharedViewModel.phone = etPhone.text.toString()

            parentFragmentManager.beginTransaction()
                .replace(R.id.fragmentContainer, PaymentFragment())
                .addToBackStack(null)
                .commit()
        }
    }
}