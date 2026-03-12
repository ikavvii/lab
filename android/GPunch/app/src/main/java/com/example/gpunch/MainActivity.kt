package com.example.gpunch

import android.Manifest
import android.content.pm.PackageManager
import android.location.Location
import android.os.Build
import android.os.Bundle
import android.widget.Button
import android.widget.TextView
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.activity.result.contract.ActivityResultContracts
import androidx.appcompat.app.AppCompatActivity
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.google.android.gms.location.FusedLocationProviderClient
import com.google.android.gms.location.LocationServices
import com.google.android.gms.location.Priority
import com.google.android.gms.tasks.CancellationTokenSource

class MainActivity : AppCompatActivity() {

    private lateinit var fusedLocationClient: FusedLocationProviderClient
    private lateinit var statusTextView: TextView
    private lateinit var locationTextView: TextView
    private lateinit var punchInButton: Button

    // Target location: 11°01'28.2"N 77°00'16.1"E
    // Converted to Decimal Degrees: 11.0245, 77.004472
    private val targetLat = 11.0245 
    private val targetLng = 77.004472
    private val geofenceRadiusMeters = 100.0

    private val requestPermissionLauncher = registerForActivityResult(
        ActivityResultContracts.RequestMultiplePermissions()
    ) { permissions ->
        when {
            permissions.getOrDefault(Manifest.permission.ACCESS_FINE_LOCATION, false) -> {
                getCurrentLocation()
            }
            permissions.getOrDefault(Manifest.permission.ACCESS_COARSE_LOCATION, false) -> {
                getCurrentLocation()
            }
            else -> {
                Toast.makeText(this, getString(R.string.permission_denied), Toast.LENGTH_SHORT).show()
            }
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        fusedLocationClient = LocationServices.getFusedLocationProviderClient(this)
        
        statusTextView = findViewById(R.id.statusTextView)
        locationTextView = findViewById(R.id.locationTextView)
        punchInButton = findViewById(R.id.punchInButton)

        punchInButton.setOnClickListener {
            checkPermissionsAndGetLocation()
        }
    }

    private fun checkPermissionsAndGetLocation() {
        if (ActivityCompat.checkSelfPermission(
                this,
                Manifest.permission.ACCESS_FINE_LOCATION
            ) != PackageManager.PERMISSION_GRANTED && ActivityCompat.checkSelfPermission(
                this,
                Manifest.permission.ACCESS_COARSE_LOCATION
            ) != PackageManager.PERMISSION_GRANTED
        ) {
            requestPermissionLauncher.launch(
                arrayOf(
                    Manifest.permission.ACCESS_FINE_LOCATION,
                    Manifest.permission.ACCESS_COARSE_LOCATION
                )
            )
            return
        }
        getCurrentLocation()
    }

    private fun getCurrentLocation() {
        if (ActivityCompat.checkSelfPermission(
                this,
                Manifest.permission.ACCESS_FINE_LOCATION
            ) != PackageManager.PERMISSION_GRANTED && ActivityCompat.checkSelfPermission(
                this,
                Manifest.permission.ACCESS_COARSE_LOCATION
            ) != PackageManager.PERMISSION_GRANTED
        ) {
            return
        }

        statusTextView.text = getString(R.string.verifying_location)
        
        fusedLocationClient.getCurrentLocation(
            Priority.PRIORITY_HIGH_ACCURACY,
            CancellationTokenSource().token
        ).addOnSuccessListener { location: Location? ->
            if (location != null) {
                // Basic check for mock locations to improve security
                val isMock = if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S) {
                    location.isMock
                } else {
                    @Suppress("DEPRECATION")
                    location.isFromMockProvider
                }

                if (isMock) {
                    statusTextView.text = "Error: Mocked location detected.\nPlease disable fake GPS."
                    statusTextView.setTextColor(ContextCompat.getColor(this, android.R.color.holo_red_dark))
                } else {
                    verifyPresence(location)
                }
            } else {
                statusTextView.text = getString(R.string.failed_get_location)
            }
        }.addOnFailureListener {
            statusTextView.text = getString(R.string.error_message, it.message)
        }
    }

    private fun verifyPresence(currentLocation: Location) {
        val results = FloatArray(1)
        Location.distanceBetween(
            currentLocation.latitude,
            currentLocation.longitude,
            targetLat,
            targetLng,
            results
        )

        val distanceInMeters = results[0]
        locationTextView.text = getString(R.string.location_format, currentLocation.latitude, currentLocation.longitude)

        if (distanceInMeters <= geofenceRadiusMeters) {
            statusTextView.text = getString(R.string.punch_in_success)
            statusTextView.setTextColor(ContextCompat.getColor(this, android.R.color.holo_green_dark))
            punchInButton.isEnabled = false
        } else {
            statusTextView.text = getString(R.string.punch_in_failed, distanceInMeters.toInt())
            statusTextView.setTextColor(ContextCompat.getColor(this, android.R.color.holo_red_dark))
        }
    }
}