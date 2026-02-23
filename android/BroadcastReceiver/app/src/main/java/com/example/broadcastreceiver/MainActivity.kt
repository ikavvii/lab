package com.example.broadcastreceiver

import android.Manifest
import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.content.IntentFilter
import android.content.pm.PackageManager
import android.location.LocationManager
import android.net.ConnectivityManager
import android.net.Network
import android.net.NetworkCapabilities
import android.net.NetworkRequest
import android.os.Bundle
import android.widget.TextView
import android.widget.Toast
import androidx.activity.result.contract.ActivityResultContracts
import androidx.appcompat.app.AppCompatActivity
import androidx.core.content.ContextCompat

class MainActivity : AppCompatActivity() {

    private lateinit var tvMobile: TextView
    private lateinit var tvInternetStatus: TextView
    private lateinit var tvLocationStatus: TextView

    private lateinit var connectivityManager: ConnectivityManager
    private lateinit var locationManager: LocationManager

    // Permission launcher
    private val requestPermissionLauncher = registerForActivityResult(
        ActivityResultContracts.RequestMultiplePermissions()
    ) { permissions ->
        val granted = permissions.entries.all { it.value }
        if (granted) {
            checkStatus()
        } else {
            Toast.makeText(this, "Location permission denied. Status will show as OFF.", Toast.LENGTH_SHORT).show()
            updateLocationUI(false)
        }
    }

    // Real-time Internet Listener
    private val networkCallback = object : ConnectivityManager.NetworkCallback() {
        override fun onAvailable(network: Network) {
            runOnUiThread { updateInternetUI(true) }
        }

        override fun onLost(network: Network) {
            runOnUiThread { updateInternetUI(false) }
        }
    }

    // Real-time Location Listener
    private val locationReceiver = object : BroadcastReceiver() {
        override fun onReceive(context: Context?, intent: Intent?) {
            if (intent?.action == LocationManager.PROVIDERS_CHANGED_ACTION) {
                checkStatus()
            }
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        tvMobile = findViewById(R.id.tv_mobile)
        tvInternetStatus = findViewById(R.id.tv_internet_status)
        tvLocationStatus = findViewById(R.id.tv_location_status)

        connectivityManager = getSystemService(CONNECTIVITY_SERVICE) as ConnectivityManager
        locationManager = getSystemService(LOCATION_SERVICE) as LocationManager

        val mobile = intent.getStringExtra("mobile_number") ?: "Unknown"
        tvMobile.text = buildString {
            append("Mobile: ")
            append(mobile)
        }
        checkAndRequestPermissions()
    }

    private fun checkAndRequestPermissions() {
        val permissions = arrayOf(
            Manifest.permission.ACCESS_FINE_LOCATION,
            Manifest.permission.ACCESS_COARSE_LOCATION
        )

        val allGranted = permissions.all {
            ContextCompat.checkSelfPermission(this, it) == PackageManager.PERMISSION_GRANTED
        }

        if (allGranted) {
            checkStatus()
        } else {
            requestPermissionLauncher.launch(permissions)
        }
    }

    override fun onStart() {
        super.onStart()
        // Register Internet Callback
        val networkRequest = NetworkRequest.Builder()
            .addCapability(NetworkCapabilities.NET_CAPABILITY_INTERNET)
            .build()
        connectivityManager.registerNetworkCallback(networkRequest, networkCallback)

        // Register Location Broadcast
        registerReceiver(locationReceiver, IntentFilter(LocationManager.PROVIDERS_CHANGED_ACTION))
        
        // Initial Check
        checkStatus()
    }

    override fun onStop() {
        super.onStop()
        connectivityManager.unregisterNetworkCallback(networkCallback)
        unregisterReceiver(locationReceiver)
    }

    private fun checkStatus() {
        updateInternetUI(isInternetAvailable())
        updateLocationUI(isLocationEnabled())
    }

    private fun updateInternetUI(isOnline: Boolean) {
        tvInternetStatus.text = if (isOnline) "Internet: ON" else "Internet: OFF"
        tvInternetStatus.setTextColor(if (isOnline) getColor(android.R.color.holo_green_dark) else getColor(android.R.color.holo_red_dark))
    }

    private fun updateLocationUI(isEnabled: Boolean) {
        tvLocationStatus.text = if (isEnabled) "Location: ON" else "Location: OFF"
        tvLocationStatus.setTextColor(if (isEnabled) getColor(android.R.color.holo_green_dark) else getColor(android.R.color.holo_red_dark))
    }

    private fun isInternetAvailable(): Boolean {
        val network = connectivityManager.activeNetwork ?: return false
        val capabilities = connectivityManager.getNetworkCapabilities(network) ?: return false
        return capabilities.hasCapability(NetworkCapabilities.NET_CAPABILITY_INTERNET)
    }

    private fun isLocationEnabled(): Boolean {
        // Check for permission first
        val hasFineLocation = ContextCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED
        val hasCoarseLocation = ContextCompat.checkSelfPermission(this, Manifest.permission.ACCESS_COARSE_LOCATION) == PackageManager.PERMISSION_GRANTED
        
        if (!hasFineLocation && !hasCoarseLocation) {
            return false
        }

        // Then check if provider is enabled
        return locationManager.isProviderEnabled(LocationManager.GPS_PROVIDER) ||
                locationManager.isProviderEnabled(LocationManager.NETWORK_PROVIDER)
    }
}
