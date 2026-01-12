package com.example.fookie

import android.os.Bundle
import android.widget.Button
import android.widget.ImageView
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {

    private val cookieMonster = CookieMonster()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        val imageView = findViewById<ImageView>(R.id.image_view_cookie_monster)
        val textView = findViewById<TextView>(R.id.text_view_status)
        val button = findViewById<Button>(R.id.button_eat_cookie)

        button.setOnClickListener {
            if (cookieMonster.isFull) {
                // Return to hungry state
                cookieMonster.becomeHungry()
                imageView.setImageResource(R.drawable.hungry)
                textView.text = getString(R.string.i_m_so_hungry)
                button.text = getString(R.string.eat_cookie)
            } else {
                // Become full
                cookieMonster.eatCookie()
                imageView.setImageResource(R.drawable.full)
                textView.text = getString(R.string.i_m_so_full)
                button.text = getString(R.string.done)
            }
        }
    }
}
