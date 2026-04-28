package com.example.mocktest1

import android.app.Service
import android.content.Intent
import android.media.MediaPlayer
import android.media.RingtoneManager
import android.os.IBinder

class MusicService : Service() {

    private var mediaPlayer: MediaPlayer? = null

    override fun onBind(intent: Intent?): IBinder? {
        return null // We are using a started service, not a bound service
    }

    override fun onCreate() {
        super.onCreate()
        // Get the default ringtone URI to play as music
        val ringtoneUri = RingtoneManager.getDefaultUri(RingtoneManager.TYPE_RINGTONE)
        mediaPlayer = MediaPlayer.create(this, ringtoneUri)
        mediaPlayer?.isLooping = true // Loop the music
    }

    override fun onStartCommand(intent: Intent?, flags: Int, startId: Int): Int {
        if (mediaPlayer?.isPlaying == false) {
            mediaPlayer?.start()
        }
        return START_STICKY // Restart service if system kills it
    }

    override fun onDestroy() {
        super.onDestroy()
        if (mediaPlayer?.isPlaying == true) {
            mediaPlayer?.stop()
        }
        mediaPlayer?.release()
    }
}