package com.example.gpunch.network

import retrofit2.Response
import retrofit2.http.Body
import retrofit2.http.POST

interface AttendanceApi {
    @POST("attendance/punch-in")
    suspend fun punchIn(@Body request: AttendanceRequest): Response<Unit>
}