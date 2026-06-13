package com.example.expensetracker

import android.app.DatePickerDialog
import android.os.Bundle
import android.widget.ArrayAdapter
import android.widget.Toast
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.navigation.fragment.findNavController
import com.example.expensetracker.databinding.FragmentSecondBinding
import com.google.firebase.Firebase
import com.google.firebase.firestore.firestore
import java.text.SimpleDateFormat
import java.util.Calendar
import java.util.Locale

/**
 * A simple [Fragment] subclass as the second destination in the navigation.
 */
class SecondFragment : Fragment() {

    private var _binding: FragmentSecondBinding? = null

    // This property is only valid between onCreateView and
    // onDestroyView.
    private val binding get() = _binding!!
    private val dateFormatter = SimpleDateFormat("yyyy-MM-dd", Locale.getDefault())
    private var editingDocumentId: String? = null

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {

        _binding = FragmentSecondBinding.inflate(inflater, container, false)
        return binding.root

    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        setupBuiltInControls()
        bindEditValuesIfAny()

        val db = Firebase.firestore

        binding.buttonSaveExpense.setOnClickListener {
            clearErrors()

            val date = binding.inputDate.text?.toString()?.trim().orEmpty()
            val amountText = binding.inputAmount.text?.toString()?.trim().orEmpty()
            val payee = binding.inputPayee.text?.toString()?.trim().orEmpty()
            val category = binding.inputCategory.text?.toString()?.trim().orEmpty()
            val payment = binding.inputPayment.text?.toString()?.trim().orEmpty()
            val description = binding.inputDescription.text?.toString()?.trim().orEmpty()
            val reference = binding.inputReference.text?.toString()?.trim().orEmpty()

            var hasError = false

            if (date.isBlank()) {
                binding.layoutDate.error = getString(R.string.error_required)
                hasError = true
            }
            if (payee.isBlank()) {
                binding.layoutPayee.error = getString(R.string.error_required)
                hasError = true
            }
            if (category.isBlank()) {
                binding.layoutCategory.error = getString(R.string.error_required)
                hasError = true
            }
            if (payment.isBlank()) {
                binding.layoutPayment.error = getString(R.string.error_required)
                hasError = true
            }
            if (reference.isBlank()) {
                binding.layoutReference.error = getString(R.string.error_required)
                hasError = true
            }

            val amount = amountText.toDoubleOrNull()
            if (amountText.isBlank()) {
                binding.layoutAmount.error = getString(R.string.error_required)
                hasError = true
            } else if (amount == null) {
                binding.layoutAmount.error = getString(R.string.error_invalid_amount)
                hasError = true
            }

            if (hasError || amount == null) {
                return@setOnClickListener
            }

            val documentId = editingDocumentId
                ?: db.collection("expenses").document().id
            val entry = hashMapOf(
                "id" to documentId,
                "date" to date,
                "amount" to amount,
                "payee" to payee,
                "category" to category,
                "payment" to payment,
                "description" to description,
                "reference" to reference
            )

            binding.buttonSaveExpense.isEnabled = false
            db.collection("expenses")
                .document(documentId)
                .set(entry)
                .addOnSuccessListener {
                    Toast.makeText(
                        requireContext(),
                        if (editingDocumentId == null) getString(R.string.expense_saved) else getString(R.string.expense_updated),
                        Toast.LENGTH_SHORT
                    ).show()
                    findNavController().popBackStack()
                }
                .addOnFailureListener { e ->
                    binding.buttonSaveExpense.isEnabled = true
                    Toast.makeText(
                        requireContext(),
                        getString(R.string.error_saving_expense, e.localizedMessage ?: ""),
                        Toast.LENGTH_LONG
                    ).show()
                }
        }

        binding.buttonSecond.setOnClickListener {
            findNavController().popBackStack()
        }
    }

    private fun setupBuiltInControls() {
        val categoryAdapter = ArrayAdapter(
            requireContext(),
            android.R.layout.simple_list_item_1,
            resources.getStringArray(R.array.expense_categories)
        )
        val paymentAdapter = ArrayAdapter(
            requireContext(),
            android.R.layout.simple_list_item_1,
            resources.getStringArray(R.array.expense_payment_methods)
        )
        binding.inputCategory.setAdapter(categoryAdapter)
        binding.inputPayment.setAdapter(paymentAdapter)

        binding.inputDate.setOnClickListener { showDatePicker() }
        binding.layoutDate.setEndIconOnClickListener { showDatePicker() }
    }

    private fun bindEditValuesIfAny() {
        editingDocumentId = arguments?.getString(ARG_DOC_ID)
        if (editingDocumentId.isNullOrBlank()) {
            return
        }

        binding.inputDate.setText(arguments?.getString(ARG_DATE).orEmpty())
        binding.inputAmount.setText(arguments?.getString(ARG_AMOUNT).orEmpty())
        binding.inputPayee.setText(arguments?.getString(ARG_PAYEE).orEmpty())
        binding.inputCategory.setText(arguments?.getString(ARG_CATEGORY).orEmpty(), false)
        binding.inputPayment.setText(arguments?.getString(ARG_PAYMENT).orEmpty(), false)
        binding.inputDescription.setText(arguments?.getString(ARG_DESCRIPTION).orEmpty())
        binding.inputReference.setText(arguments?.getString(ARG_REFERENCE).orEmpty())
        binding.buttonSaveExpense.setText(R.string.update_expense)
    }

    private fun showDatePicker() {
        val selectedDate = binding.inputDate.text?.toString()?.trim().orEmpty()
        val calendar = Calendar.getInstance()
        if (selectedDate.isNotBlank()) {
            runCatching { dateFormatter.parse(selectedDate) }.getOrNull()?.let { parsedDate ->
                calendar.time = parsedDate
            }
        }
        val picker = DatePickerDialog(
            requireContext(),
            { _, year, month, dayOfMonth ->
                calendar.set(year, month, dayOfMonth)
                binding.inputDate.setText(dateFormatter.format(calendar.time))
            },
            calendar.get(Calendar.YEAR),
            calendar.get(Calendar.MONTH),
            calendar.get(Calendar.DAY_OF_MONTH)
        )
        picker.show()
    }

    private fun clearErrors() {
        binding.layoutDate.error = null
        binding.layoutAmount.error = null
        binding.layoutPayee.error = null
        binding.layoutCategory.error = null
        binding.layoutPayment.error = null
        binding.layoutDescription.error = null
        binding.layoutReference.error = null
    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }

    companion object {
        const val ARG_DOC_ID = "argDocId"
        const val ARG_DATE = "argDate"
        const val ARG_AMOUNT = "argAmount"
        const val ARG_PAYEE = "argPayee"
        const val ARG_CATEGORY = "argCategory"
        const val ARG_PAYMENT = "argPayment"
        const val ARG_DESCRIPTION = "argDescription"
        const val ARG_REFERENCE = "argReference"
    }
}
