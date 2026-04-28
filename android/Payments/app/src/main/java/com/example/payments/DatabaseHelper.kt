package com.example.payments

import android.content.ContentValues
import android.content.Context
import android.database.Cursor
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper

class DatabaseHelper(context: Context) : SQLiteOpenHelper(context, "UserDB.db", null, 1) {

    companion object {
        const val TABLE_NAME = "users"
    }

    override fun onCreate(db: SQLiteDatabase) {
        val createTable = """
            CREATE TABLE $TABLE_NAME (
                ID INTEGER PRIMARY KEY AUTOINCREMENT,
                EMAIL TEXT, USERNAME TEXT, PASSWORD TEXT,
                FIRST_NAME TEXT, PHONE TEXT, CARD_NUMBER TEXT
            )
        """.trimIndent()
        db.execSQL(createTable)
    }

    override fun onUpgrade(db: SQLiteDatabase, oldVersion: Int, newVersion: Int) {
        db.execSQL("DROP TABLE IF EXISTS $TABLE_NAME")
        onCreate(db)
    }

    fun insertUserData(
        email: String, username: String, pass: String,
        fName: String, phone: String, card: String
    ): Boolean {
        val db = this.writableDatabase
        val values = ContentValues().apply {
            put("EMAIL", email)
            put("USERNAME", username)
            put("PASSWORD", pass)
            put("FIRST_NAME", fName)
            put("PHONE", phone)
            put("CARD_NUMBER", card)
        }
        val result = db.insert(TABLE_NAME, null, values)
        return result != -1L
    }

    fun getAllData(): Cursor {
        val db = this.readableDatabase
        return db.rawQuery("SELECT * FROM $TABLE_NAME", null)
    }
}