package com.example.calculator

import android.os.Bundle
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.google.android.material.button.MaterialButton

class MainActivity : AppCompatActivity() {

    private lateinit var tvDisplay: TextView
    private lateinit var tvFormula: TextView
    private var firstOperand: Double? = null
    private var currentOperator: String? = null
    private var isNewOp = true

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        tvDisplay = findViewById(R.id.tvDisplay)
        tvFormula = findViewById(R.id.tvFormula)

        // Setup digit buttons
        val digitButtons = listOf(
            R.id.btn0, R.id.btn1, R.id.btn2, R.id.btn3, R.id.btn4,
            R.id.btn5, R.id.btn6, R.id.btn7, R.id.btn8, R.id.btn9
        )
        digitButtons.forEach { id ->
            findViewById<MaterialButton>(id).setOnClickListener {
                appendNumber((it as MaterialButton).text.toString())
            }
        }

        findViewById<MaterialButton>(R.id.btnDot).setOnClickListener { appendDot() }
        findViewById<MaterialButton>(R.id.btnAC).setOnClickListener { clear() }

        // Setup operator buttons
        findViewById<MaterialButton>(R.id.btnAdd).setOnClickListener { setOperator("+") }
        findViewById<MaterialButton>(R.id.btnSubtract).setOnClickListener { setOperator("-") }
        findViewById<MaterialButton>(R.id.btnMultiply).setOnClickListener { setOperator("*") }
        findViewById<MaterialButton>(R.id.btnDivide).setOnClickListener { setOperator("/") }

        findViewById<MaterialButton>(R.id.btnEqual).setOnClickListener { calculate() }
    }

    private fun appendNumber(number: String) {
        if (isNewOp) {
            // If starting a fresh calculation after a result, clear the formula bar
            if (currentOperator == null) {
                tvFormula.text = ""
                firstOperand = null
            }
            tvDisplay.text = number
            isNewOp = false
        } else {
            if (tvDisplay.text.toString() == "0") {
                tvDisplay.text = number
            } else {
                tvDisplay.append(number)
            }
        }
    }

    private fun appendDot() {
        if (isNewOp) {
            tvDisplay.text = "0."
            isNewOp = false
            return
        }
        if (!tvDisplay.text.contains(".")) {
            tvDisplay.append(".")
        }
    }

    private fun setOperator(operator: String) {
        // Allow overriding the operator if the second operand hasn't been typed yet
        if (isNewOp && currentOperator != null) {
            currentOperator = operator
            tvFormula.text = "${formatDisplay(firstOperand)} $operator"
            return
        }

        firstOperand = tvDisplay.text.toString().toDoubleOrNull()
        currentOperator = operator
        tvFormula.text = "${formatDisplay(firstOperand)} $operator"
        tvDisplay.text = "0" // Explicitly reset input bar to "0"
        isNewOp = true
    }

    private fun calculate() {
        val secondOperand = tvDisplay.text.toString().toDoubleOrNull()
        
        if (firstOperand != null && currentOperator != null && secondOperand != null) {
            val result = when (currentOperator) {
                "+" -> firstOperand!! + secondOperand
                "-" -> firstOperand!! - secondOperand
                "*" -> firstOperand!! * secondOperand
                "/" -> if (secondOperand != 0.0) firstOperand!! / secondOperand else Double.NaN
                else -> secondOperand
            }

            tvFormula.text = "${formatDisplay(firstOperand)} $currentOperator ${formatDisplay(secondOperand)} ="
            tvDisplay.text = if (result.isNaN()) getString(R.string.error) else formatDisplay(result)
            
            // Prepare for next operation
            firstOperand = if (result.isNaN()) null else result
            currentOperator = null
            isNewOp = true
        }
    }

    private fun clear() {
        tvDisplay.text = "0"
        tvFormula.text = ""
        firstOperand = null
        currentOperator = null
        isNewOp = true
    }

    private fun formatDisplay(value: Double?): String {
        if (value == null) return ""
        return if (value % 1 == 0.0) value.toLong().toString() else value.toString()
    }
}
