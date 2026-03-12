package com.example.gpunch.network

data class AttendanceRequest(
    val userId: String,
    val latitude: Double,
    val longitude: Double,
    val timestamp: Long,
    val status: String = "ONSITE"
)