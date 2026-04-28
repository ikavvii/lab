package com.example.payments

import android.os.Bundle
import android.view.View
import android.widget.TextView
import androidx.fragment.app.Fragment
import androidx.fragment.app.FragmentManager
import androidx.activity.OnBackPressedCallback

class DisplayFragment : Fragment(R.layout.fragment_display) {
    private lateinit var dbHelper: DatabaseHelper

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        dbHelper = DatabaseHelper(requireContext())

        requireActivity().onBackPressedDispatcher.addCallback(viewLifecycleOwner, object : OnBackPressedCallback(true) {
            override fun handleOnBackPressed() {
                // 1. Clear any weird history remaining in the back stack
                parentFragmentManager.popBackStack(null, FragmentManager.POP_BACK_STACK_INCLUSIVE)

                // 2. Force it to load Step 1 (AccountFragment)
                parentFragmentManager.beginTransaction()
                    .replace(R.id.fragmentContainer, AccountFragment())
                    .commit()
            }
        })
        val tvRecords = view.findViewById<TextView>(R.id.tvDatabaseRecords)
        val cursor = dbHelper.getAllData()

        if (cursor.count == 0) {
            tvRecords.text = "No records found."
            return
        }

        val buffer = StringBuilder()
        while (cursor.moveToNext()) {
            buffer.append("ID: ${cursor.getString(0)}\n")
            buffer.append("Email: ${cursor.getString(1)}\n")
            buffer.append("User: ${cursor.getString(2)}\n")
            buffer.append("Name: ${cursor.getString(4)}\n")
            buffer.append("Phone: ${cursor.getString(5)}\n")
            buffer.append("---------------------------\n")
        }
        tvRecords.text = buffer.toString()
        cursor.close()


    }
}