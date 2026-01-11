package com.example.fookie

class CookieMonster {
    var isFull: Boolean = false
        private set

    fun eatCookie() {
        isFull = true
    }

    fun becomeHungry() {
        isFull = false
    }
}
