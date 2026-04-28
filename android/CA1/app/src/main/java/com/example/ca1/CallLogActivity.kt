package com.example.ca1

import android.Manifest
import android.content.pm.PackageManager
import android.os.Bundle
import android.provider.CallLog
import android.widget.ListView
import android.widget.SimpleCursorAdapter
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class CallLogActivity : AppCompatActivity() {

    private lateinit var list: ListView
    private val PERMISSIONS_REQUEST_READ_CALL_LOG = 1

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_call_log)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        list = findViewById(R.id.list)

        if (ContextCompat.checkSelfPermission(this, Manifest.permission.READ_CALL_LOG)
            != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this,
                arrayOf(Manifest.permission.READ_CALL_LOG),
                PERMISSIONS_REQUEST_READ_CALL_LOG)
        } else {
            readCallLog()
        }
    }

    override fun onRequestPermissionsResult(requestCode: Int, permissions: Array<out String>, grantResults: IntArray) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults)
        if (requestCode == PERMISSIONS_REQUEST_READ_CALL_LOG) {
            if (grantResults.isNotEmpty() && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                readCallLog()
            } else {
                Toast.makeText(this, "Permission denied to read call logs", Toast.LENGTH_SHORT).show()
            }
        }
    }

    private fun readCallLog() {
        val callUri = CallLog.Calls.CONTENT_URI

        // SimpleCursorAdapter requires _ID column
        val projection = arrayOf(
            CallLog.Calls._ID,
            CallLog.Calls.NUMBER,
            CallLog.Calls.TYPE,
            CallLog.Calls.DATE
        )

        val from = arrayOf(
            CallLog.Calls.NUMBER,
            CallLog.Calls.TYPE
        )

        val to = intArrayOf(android.R.id.text1, android.R.id.text2)

        val sortOrder = "${CallLog.Calls.DATE} DESC"

        val cursor = contentResolver.query(callUri, projection, null, null, sortOrder)

        if (cursor != null) {
            val adapter = SimpleCursorAdapter(
                this,
                android.R.layout.simple_list_item_2,
                cursor,
                from,
                to,
                0
            )
            list.adapter = adapter
        }
    }
}
