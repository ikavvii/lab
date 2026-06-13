package com.example.ca1

import android.app.DatePickerDialog
import android.content.Intent
import android.os.Bundle
import android.widget.ArrayAdapter
import android.widget.AutoCompleteTextView
import android.widget.Button
import android.widget.EditText
import android.widget.Spinner
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import java.util.Calendar

class FormActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_form)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        val button = findViewById<Button>(R.id.button)

        val firstName = findViewById<EditText>(R.id.firstname)
val middleName = findViewById<EditText>(R.id.middlename)
        val lastName = findViewById<EditText>(R.id.lastname)

        val phone = findViewById<EditText>(R.id.phone)

        val email = findViewById<EditText>(R.id.email)

        val address = findViewById<EditText>(R.id.address)

        val dob = findViewById<EditText>(R.id.dob)

        val group = findViewById<AutoCompleteTextView>(R.id.group)

        val groups = arrayOf("Group 1", "Group 2", "Group 3")
        val adapter = ArrayAdapter(this, android.R.layout.simple_dropdown_item_1line, groups)

        group.setAdapter(adapter)

        val phoneType = findViewById<Spinner>(R.id.phone_type)
        val emailType = findViewById<Spinner>(R.id.email_type)
        val addressType = findViewById<Spinner>(R.id.address_type)


        val types = arrayOf("Home", "Work", "Mobile")


        val phoneTypeAdapter = ArrayAdapter(this, android.R.layout.simple_dropdown_item_1line, types)
        val emailTypeAdapter = ArrayAdapter(this, android.R.layout.simple_dropdown_item_1line, types)
        val addressTypeAdapter = ArrayAdapter(this, android.R.layout.simple_dropdown_item_1line, types)


        phoneType.adapter = phoneTypeAdapter
        emailType.adapter = emailTypeAdapter
        addressType.adapter = addressTypeAdapter

        dob.setOnClickListener {
            val c = Calendar.getInstance()
            val year = c.get(Calendar.YEAR)
            val month = c.get(Calendar.MONTH)
            val day = c.get(Calendar.DAY_OF_MONTH)

            val datePickerDialog =
                DatePickerDialog(this, { _, selectedYear, selectedMonth, selectedDay ->
                    // Months are 0-indexed (0 = Jan), so we add 1
                    val dateString = "$selectedDay/${selectedMonth + 1}/$selectedYear"
                    dob.setText(dateString)
                }, year, month, day)

            datePickerDialog.show()
        }

        button.setOnClickListener {

            val firstNameValue = firstName.text.toString()

            val middleNameValue = middleName.text.toString()

            val lastNameValue = lastName.text.toString()

            val phoneValue = phone.text.toString()

            val emailValue = email.text.toString()

            val addressValue = address.text.toString()

            val dobValue = dob.text.toString()

            val groupValue = group.text.toString()


            if (firstNameValue.isEmpty() || middleNameValue.isEmpty() || lastNameValue.isEmpty() || phoneValue.isEmpty() || emailValue.isEmpty() || addressValue.isEmpty() || dobValue.isEmpty() || groupValue.isEmpty()) {
                Toast.makeText(this, "Please fill all the fields", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }

            val intent = Intent(this, MainActivity::class.java).apply {
                putExtra("data", true)
                putExtra("firstName", firstNameValue)
                putExtra("middleName", middleNameValue)
                putExtra("lastName", lastNameValue)
                putExtra("phone", phoneValue)
                putExtra("email", emailValue)
                putExtra("address", addressValue)
                putExtra("dob", dobValue)
                putExtra("group", groupValue)
                putExtra("phone_type", phoneType.selectedItem.toString())
                putExtra("email_type", emailType.selectedItem.toString())
                putExtra("address_type", addressType.selectedItem.toString())
            }
            startActivity(intent)
        }
    }
}