package com.example.broadcastreceiverex
import android.content.Context
import android.content.ContextWrapper
import android.content.pm.PackageManager
import android.util.Base64
import android.util.Log
import java.nio.charset.StandardCharsets
import java.security.MessageDigest
import java.security.NoSuchAlgorithmException

class AppSignatureHelper(context: Context) : ContextWrapper(context) {

    val appSignatures: ArrayList<String>
        get() {
            val appCodes = ArrayList<String>()
            try {
                val packageName = packageName
                val packageManager = packageManager

                // Check if the device is running Android 9 (Pie) or higher
                val signatures = if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.P) {
                    val signingInfo = packageManager.getPackageInfo(
                        packageName,
                        PackageManager.GET_SIGNING_CERTIFICATES
                    ).signingInfo

                    if (signingInfo == null) return appCodes

                    if (signingInfo.hasMultipleSigners()) {
                        signingInfo.apkContentsSigners
                    } else {
                        signingInfo.signingCertificateHistory
                    }
                } else {
                    // Fallback for older Android versions
                    @Suppress("DEPRECATION")
                    packageManager.getPackageInfo(
                        packageName,
                        PackageManager.GET_SIGNATURES
                    ).signatures
                }

                if (signatures != null) {
                    for (signature in signatures) {
                        val hash = hash(packageName, signature.toCharsString())
                        if (hash != null) {
                            appCodes.add(String.format("%s", hash))
                        }
                    }
                }
            } catch (e: Exception) {
                Log.e(TAG, "Unable to find package to obtain hash.", e)
            }
            return appCodes
        }

    companion object {
        val TAG: String = AppSignatureHelper::class.java.simpleName
        private const val HASH_TYPE = "SHA-256"
        private const val NUM_HASHED_BYTES = 9
        private const val NUM_BASE64_CHAR = 11

        private fun hash(packageName: String, signature: String): String? {
            val appInfo = "$packageName $signature"
            try {
                val messageDigest = MessageDigest.getInstance(HASH_TYPE)
                messageDigest.update(appInfo.toByteArray(StandardCharsets.UTF_8))
                var hashSignature = messageDigest.digest()
                hashSignature = hashSignature.copyOfRange(0, NUM_HASHED_BYTES)
                var base64Hash = Base64.encodeToString(hashSignature, Base64.NO_PADDING or Base64.NO_WRAP)
                base64Hash = base64Hash.take(NUM_BASE64_CHAR)
                return base64Hash
            } catch (e: NoSuchAlgorithmException) {
                Log.e(TAG, "hash:NoSuchAlgorithm", e)
            }
            return null
        }
    }
}