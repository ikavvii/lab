package com.example.mocktest1

import android.content.Intent
import android.content.res.Configuration
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.app.AppCompatDelegate

class MainActivity : AppCompatActivity() {

    private var isMusicPlaying = false

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        // Note: Make sure your app theme in themes.xml is a "DayNight" theme
        // with an ActionBar, e.g., Theme.AppCompat.DayNight.DarkActionBar
    }

    // Inflate the menu
    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.main_menu, menu)
        return true
    }

    // Dynamically update menu text before it is shown
    override fun onPrepareOptionsMenu(menu: Menu?): Boolean {
        val themeItem = menu?.findItem(R.id.action_theme)
        val musicItem = menu?.findItem(R.id.action_music)

        // Check current theme state to set the toggle text correctly
        val isNightMode = resources.configuration.uiMode and Configuration.UI_MODE_NIGHT_MASK == Configuration.UI_MODE_NIGHT_YES
        themeItem?.title = if (isNightMode) "Light Theme" else "Dark Theme"

        // Update music text
        musicItem?.title = if (isMusicPlaying) "Stop Music" else "Play Music"

        return super.onPrepareOptionsMenu(menu)
    }

    // Handle menu item clicks
    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        return when (item.itemId) {
            R.id.action_whatsapp -> {
                val intent = Intent(this, WhatsappSend::class.java)
                startActivity(intent)
                true
            }
            R.id.action_music -> {
                val serviceIntent = Intent(this, MusicService::class.java)
                if (isMusicPlaying) {
                    stopService(serviceIntent)
                    isMusicPlaying = false
                    Toast.makeText(this, "Music Stopped", Toast.LENGTH_SHORT).show()
                } else {
                    startService(serviceIntent)
                    isMusicPlaying = true
                    Toast.makeText(this, "Music Playing in Background", Toast.LENGTH_SHORT).show()
                }
                invalidateOptionsMenu() // Refresh menu text
                true
            }
            R.id.action_theme -> {
                val isNightMode = resources.configuration.uiMode and Configuration.UI_MODE_NIGHT_MASK == Configuration.UI_MODE_NIGHT_YES
                if (isNightMode) {
                    AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO)
                } else {
                    AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_YES)
                }
                true
            }
            else -> super.onOptionsItemSelected(item)
        }
    }
}