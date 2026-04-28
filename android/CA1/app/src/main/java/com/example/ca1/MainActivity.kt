package com.example.ca1

import android.content.Intent
import android.os.Bundle
import android.view.ContextMenu
import android.view.MenuItem
import android.view.View
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    private lateinit var t: TextView
    private lateinit var res: TextView
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        t = findViewById(R.id.welcome)
        registerForContextMenu(t)

        if (intent.getBooleanExtra("data", false)) {
            val firstName = intent.getStringExtra("firstName")
            val middleName = intent.getStringExtra("middleName")
            val lastName = intent.getStringExtra("lastName")
            val phone = intent.getStringExtra("phone")
            val email = intent.getStringExtra("email")
            val address = intent.getStringExtra("address")
            val dob = intent.getStringExtra("dob")
            val group = intent.getStringExtra("group")
            val phoneType = intent.getStringExtra("phone_type")
            val emailType = intent.getStringExtra("email_type")
            val addressType = intent.getStringExtra("address_type")

            res = findViewById(R.id.result)
            res.text = "First Name: $firstName\n" +
                    "Middle Name: $middleName\n" +
                    "Last Name: $lastName\n" +
                    "Phone: $phone\n" +
                    "Email: $email\n" +
                    "Address: $address\n" +
                    "Date of Birth: $dob\n" +
                    "Group: $group\n" +
                    "Phone Type: $phoneType\n" +
                    "Email Type: $emailType\n" +
                    "Address Type: $addressType"
        }
    }
    override fun onCreateContextMenu(
        menu: ContextMenu?,
        v: View?,
        menuInfo: ContextMenu.ContextMenuInfo?
    ) {
        super.onCreateContextMenu(menu, v, menuInfo)
        menuInflater.inflate(R.menu.main_menu,menu)
        menu?.setHeaderTitle("Select action")
    }

    override fun onContextItemSelected(item: MenuItem): Boolean {
        return when (item.itemId) {
            R.id.action_form -> {
                val intent = Intent(this, FormActivity::class.java)
                startActivity(intent)
                true
            }
            R.id.action_internet -> {
                val intent = Intent(this, InternetActivity::class.java)
                startActivity(intent)
                true

            }
            R.id.action_call_logs -> {
                val intent = Intent(this, CallLogActivity::class.java)
                startActivity(intent)
                true
            }
            else -> super.onOptionsItemSelected(item)
        }
    }
}