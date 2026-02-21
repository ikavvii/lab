package com.example.broadcastreceiver

import android.content.Context
import android.location.LocationManager
import android.net.ConnectivityManager
import android.net.NetworkCapabilities
import android.os.Bundle
import android.widget.Button
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {

    private lateinit var tvMobile: TextView
    private lateinit var tvInternetStatus: TextView
    private lateinit var tvLocationStatus: TextView
    private lateinit var btnRefresh: Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        tvMobile = findViewById(R.id.tv_mobile)
        tvInternetStatus = findViewById(R.id.tv_internet_status)
        tvLocationStatus = findViewById(R.id.tv_location_status)
        btnRefresh = findViewById(R.id.btn_refresh)

        // Get mobile number from intent
        val mobile = intent.getStringExtra("mobile_number") ?: "Unknown"
        tvMobile.text = "Mobile: $mobile"

        btnRefresh.setOnClickListener {
            checkStatus()
        }

        checkStatus()
    }

    private fun checkStatus() {
        // Internet Status
        val internetOn = isInternetAvailable()
        tvInternetStatus.text = if (internetOn) "Internet: ON" else "Internet: OFF"

        // Location Status
        val locationOn = isLocationEnabled()
        tvLocationStatus.text = if (locationOn) "Location: ON" else "Location: OFF"
    }

    private fun isInternetAvailable(): Boolean {
        val connectivityManager = getSystemService(Context.CONNECTIVITY_SERVICE) as ConnectivityManager
        val network = connectivityManager.activeNetwork ?: return false
        val capabilities = connectivityManager.getNetworkCapabilities(network) ?: return false
        return capabilities.hasCapability(NetworkCapabilities.NET_CAPABILITY_INTERNET)
    }

    private fun isLocationEnabled(): Boolean {
        val locationManager = getSystemService(Context.LOCATION_SERVICE) as LocationManager
        return locationManager.isProviderEnabled(LocationManager.GPS_PROVIDER) ||
                locationManager.isProviderEnabled(LocationManager.NETWORK_PROVIDER)
    }
}
