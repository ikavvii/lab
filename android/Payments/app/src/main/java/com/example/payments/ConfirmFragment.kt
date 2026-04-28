package com.example.payments

import android.Manifest
import android.app.NotificationChannel
import android.app.NotificationManager
import android.content.Context
import android.content.pm.PackageManager
import android.os.Build
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.TextView
import android.widget.Toast
import androidx.core.app.ActivityCompat
import androidx.core.app.NotificationCompat
import androidx.core.content.ContextCompat
import androidx.fragment.app.Fragment
import androidx.fragment.app.activityViewModels

class ConfirmFragment : Fragment(R.layout.fragment_confirm) {

    private val sharedViewModel: RegistrationViewModel by activityViewModels()
    private lateinit var dbHelper: DatabaseHelper

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        dbHelper = DatabaseHelper(requireContext())

        val tvSummary = view.findViewById<TextView>(R.id.tvSummary)
        val btnSubmit = view.findViewById<Button>(R.id.btnSubmit)

        val summaryText = """
            Email: ${sharedViewModel.email}
            Username: ${sharedViewModel.username}
            Name: ${sharedViewModel.firstName}
            Phone: ${sharedViewModel.phone}
            Card: **** **** **** ${sharedViewModel.cardNumber.takeLast(4)}
        """.trimIndent()
        tvSummary.text = summaryText

        btnSubmit.setOnClickListener {
            val isInserted = dbHelper.insertUserData(
                sharedViewModel.email, sharedViewModel.username, sharedViewModel.password,
                sharedViewModel.firstName, sharedViewModel.phone, sharedViewModel.cardNumber
            )

            if (isInserted) {
                checkNotificationPermissionAndSend()
                parentFragmentManager.popBackStack(null, androidx.fragment.app.FragmentManager.POP_BACK_STACK_INCLUSIVE)
                parentFragmentManager.beginTransaction()
                    .replace(R.id.fragmentContainer, DisplayFragment())
                    .addToBackStack(null)
                    .commit()
            } else {
                Toast.makeText(context, "Failed to save data.", Toast.LENGTH_SHORT).show()
            }
        }
    }

    private fun checkNotificationPermissionAndSend() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU) {
            if (ContextCompat.checkSelfPermission(requireContext(), Manifest.permission.POST_NOTIFICATIONS) == PackageManager.PERMISSION_GRANTED) {
                sendNotification()
            } else {
                ActivityCompat.requestPermissions(requireActivity(), arrayOf(Manifest.permission.POST_NOTIFICATIONS), 101)
            }
        } else {
            sendNotification()
        }
    }

    private fun sendNotification() {
        val nm = requireContext().getSystemService(Context.NOTIFICATION_SERVICE) as NotificationManager
        val channelId = "reg_channel"

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            val channel = NotificationChannel(channelId, "Registrations", NotificationManager.IMPORTANCE_DEFAULT)
            nm.createNotificationChannel(channel)
        }

        val notification = NotificationCompat.Builder(requireContext(), channelId)
            .setContentTitle("Success")
            .setContentText("Your details saved")
            .setSmallIcon(android.R.drawable.ic_dialog_info)
            .build()
        nm.notify(1, notification)
    }
}