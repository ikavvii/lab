package com.example.adapters

import android.content.Intent
import android.os.Bundle
import android.util.Log
import android.widget.AdapterView
import android.widget.ArrayAdapter
import android.widget.Button
import android.widget.ListView
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        val array = arrayOf("MCA", "MBA", "ME", "M SC", "BE", "B TECH", "B SC")

        val listView : ListView = findViewById(R.id.listView)

        val adapter = ArrayAdapter(this, android.R.layout.simple_list_item_1, array)

        listView.adapter = adapter

        listView.onItemClickListener = AdapterView.OnItemClickListener { parent, view, position, id ->
            Toast.makeText(this, "Clicked item : "+array[position], Toast.LENGTH_SHORT).show()

            Log.i("MainActivity", "Clicked item : "+array[position] + "\nParent: " + parent +
                    "\nView: $view\nPosition: $position\nId: $id")
        }

        findViewById<Button>(R.id.button).setOnClickListener {
            startActivity(Intent(this, MainActivity2::class.java))
        }
    }

}