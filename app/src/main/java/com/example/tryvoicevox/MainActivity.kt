package com.example.tryvoicevox

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.example.tryvoicevox.databinding.ActivityMainBinding
import voicevox.native_libJNI.voicevox_get_version

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = voicevox_get_version()
    }

    companion object {
        // Used to load the 'voicevox_core' library on application startup.
        init {
            System.loadLibrary("c++_shared")
            System.loadLibrary("voicevox_core")
            System.loadLibrary("native_lib")
        }
    }
}