package com.example.studentregistration

import android.app.DatePickerDialog
import android.content.Intent
import android.os.Bundle
import android.widget.ArrayAdapter
import android.widget.Button
import android.widget.EditText
import android.widget.MultiAutoCompleteTextView
import android.widget.RadioButton
import android.widget.RadioGroup
import android.widget.Spinner
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import java.util.Calendar

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

        val name = findViewById<EditText>(R.id.name)
        val roll = findViewById<EditText>(R.id.roll)
        val gender = findViewById<RadioGroup>(R.id.gender)

        val hobby = arrayOf("Coding", "Reading", "Swimming", "Gaming", "Hiking")
        val adapter = ArrayAdapter(this, android.R.layout.simple_dropdown_item_1line, hobby)
        val hobbies = findViewById<MultiAutoCompleteTextView>(R.id.hobbies)

        hobbies.setTokenizer(MultiAutoCompleteTextView.CommaTokenizer())
        hobbies.setAdapter(adapter)

        val submit = findViewById<Button>(R.id.submit)
        val programme = findViewById<Spinner>(R.id.programme)
        val programmeAdapter = ArrayAdapter.createFromResource(
            this,
            R.array.programme_array,
            android.R.layout.simple_spinner_item
        )
        programmeAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)
        programme.adapter = programmeAdapter

        val dob = findViewById<EditText>(R.id.dob)

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
        submit.setOnClickListener {

            val nameText = name.text.toString()
            val rollText = roll.text.toString()

            // 1. Get the ID of the selected RadioButton
            val selectedId = gender.checkedRadioButtonId

            if (selectedId == -1) { // Check if something is actually selected

                // Handle validation error
                Toast.makeText(this, "Please select a gender", Toast.LENGTH_SHORT).show()
                return@setOnClickListener  // // Stop the intent from firing
            }
            val genderText = findViewById<RadioButton>(selectedId).text.toString()
            val dobText = dob.text.toString()

            if (nameText.isEmpty() || rollText.isEmpty() || dobText.isEmpty()) {
                Toast.makeText(this, "Please fill all fields", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }

            val intent = Intent(this, MainActivity2::class.java).apply {
                putExtra("name", nameText)
                putExtra("roll", rollText)
                putExtra("gender", genderText)
                putExtra("hobbies", hobbies.text.toString())
                putExtra("programme", programme.selectedItem.toString())
                putExtra("dob", dobText)
            }
            startActivity(intent)
        }

    }
}