package com.example.ca1

import android.net.ConnectivityManager
import android.net.Network
import android.net.NetworkCapabilities
import android.net.NetworkRequest
import android.os.Bundle
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class InternetActivity : AppCompatActivity() {
    private lateinit var status: TextView

    private lateinit var connectivityManager: ConnectivityManager
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()


        setContentView(R.layout.activity_internet)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
        status = findViewById(R.id.textView)
        connectivityManager = getSystemService(CONNECTIVITY_SERVICE) as ConnectivityManager

    }
    override fun onStart() {
        super.onStart()
        // Register Internet Callback
        val networkRequest = NetworkRequest.Builder()
            .addCapability(NetworkCapabilities.NET_CAPABILITY_INTERNET)
            .build()
        connectivityManager.registerNetworkCallback(networkRequest, networkCallback)


        // Initial Check
        checkStatus()
    }

    override fun onResume() {
        super.onResume()
        // Check statuses that might have changed while app was in background
        checkStatus()
    }
    override fun onStop() {
        super.onStop()
        connectivityManager.unregisterNetworkCallback(networkCallback)
    }

    private fun checkStatus() {
        updateInternetUI(isInternetAvailable())
    }

    private val networkCallback = object : ConnectivityManager.NetworkCallback() {
        override fun onAvailable(network: Network) {
            runOnUiThread { updateInternetUI(true) }
        }


        override fun onLost(network: Network) {
            runOnUiThread { updateInternetUI(false) }
        }
    }

    private fun updateInternetUI(isOnline: Boolean) {
        status.text = if (isOnline) "Internet: ON" else "Internet: OFF"
        status.setTextColor(if (isOnline) getColor(android.R.color.holo_green_dark) else getColor(android.R.color.holo_red_dark))
    }

    private fun isInternetAvailable(): Boolean {
        val network = connectivityManager.activeNetwork ?: return false
        val capabilities = connectivityManager.getNetworkCapabilities(network) ?: return false
        return capabilities.hasCapability(NetworkCapabilities.NET_CAPABILITY_INTERNET)
    }




}