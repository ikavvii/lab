package com.example.contactsapp

import android.Manifest
import android.content.ContentResolver
import android.content.Intent
import android.content.pm.PackageManager
import android.database.Cursor
import android.os.Bundle
import android.provider.ContactsContract
import android.widget.AdapterView
import android.widget.ListView
import android.widget.SearchView
import android.widget.SimpleCursorAdapter
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat
import androidx.core.net.toUri
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {
    var cols = listOf(
        ContactsContract.CommonDataKinds.Phone.DISPLAY_NAME,
        ContactsContract.CommonDataKinds.Phone.NUMBER,
        ContactsContract.CommonDataKinds.Phone._ID
    ).toTypedArray()

    private lateinit var l1: ListView

    private lateinit var searchView: SearchView
    private lateinit var c: Intent
    private lateinit var cur: Cursor
    private lateinit var i:String
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
        l1 = findViewById(R.id.listView)

        searchView = findViewById(R.id.searchView)

        c = Intent(Intent.ACTION_CALL)
        if (ContextCompat.checkSelfPermission(
                this,
                Manifest.permission.READ_CONTACTS
            ) != PackageManager.PERMISSION_GRANTED
        ) {

            ActivityCompat.requestPermissions(
                this,
                Array(1) { Manifest.permission.READ_CONTACTS },
                111
            )
        } else {
            readContact()
        }

        l1.onItemClickListener = AdapterView.OnItemClickListener { parent, _, position, _ ->
            cur = parent.adapter.getItem(position) as Cursor
            i = cur.getString(cur.getColumnIndexOrThrow("data1")) as String

            start()
        }

        searchView.setOnQueryTextListener(object : SearchView.OnQueryTextListener {
            override fun onQueryTextSubmit(query: String?): Boolean {
                // This triggers when the user hits the "Search" icon/button
                return false
            }

            override fun onQueryTextChange(newText: String?): Boolean {
                // This triggers every time a letter is typed or deleted
                readContact(newText)
                return false
            }
        })

    }

    override fun onRequestPermissionsResult(
        requestCode: Int,
        permissions: Array<out String>,
        grantResults: IntArray
    ) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults)
        if (requestCode == 111 && grantResults[0] == PackageManager.PERMISSION_GRANTED)
            readContact()
        if(requestCode==112 && grantResults[0]==PackageManager.PERMISSION_GRANTED) {

            start()
        }
    }
    private fun readContact(query: String? = null) {
        val from = listOf(
            ContactsContract.CommonDataKinds.Phone.DISPLAY_NAME,
            ContactsContract.CommonDataKinds.Phone.NUMBER,
            ContactsContract.CommonDataKinds.Phone._ID
        ).toTypedArray()
        val to = intArrayOf(android.R.id.text1, android.R.id.text2)

        val selection  = if (query != null) "${ContactsContract.CommonDataKinds.Phone.DISPLAY_NAME} LIKE ?" else null
        val selectionArgs = if (query != null) arrayOf("%$query%") else null


        val c: ContentResolver = contentResolver
        val s = c.query(
            ContactsContract.CommonDataKinds.Phone.CONTENT_URI,
            cols,
            selection,
            selectionArgs,
            ContactsContract.CommonDataKinds.Phone.DISPLAY_NAME
        )

        val a = SimpleCursorAdapter(this, android.R.layout.simple_list_item_2, s, from, to, 0)
        l1.adapter = a
    }
    private fun start() {
        if (ContextCompat.checkSelfPermission(
                this@MainActivity,
                Manifest.permission.CALL_PHONE
            ) != PackageManager.PERMISSION_GRANTED
        ) {

            ActivityCompat.requestPermissions(
                this,
                Array(1) { Manifest.permission.CALL_PHONE }, 112
            )

        } else {
            c.data = ("tel:$i").toUri()
            startActivity(c)
        }
    }

}