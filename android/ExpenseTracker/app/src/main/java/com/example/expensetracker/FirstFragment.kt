package com.example.expensetracker

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ArrayAdapter
import android.widget.ListView
import android.widget.SearchView
import android.widget.TextView
import androidx.navigation.fragment.findNavController
import com.example.expensetracker.databinding.FragmentFirstBinding
import com.google.firebase.Firebase
import com.google.firebase.firestore.firestore
import java.util.Locale

/**
 * A simple [Fragment] subclass as the default destination in the navigation.
 */
class FirstFragment : Fragment() {

    private var _binding: FragmentFirstBinding? = null

    // This property is only valid between onCreateView and
    // onDestroyView.
    private val binding get() = _binding!!

    private lateinit var listView: ListView
    private var allItems: List<ExpenseListItem> = emptyList()
    private var filteredItems: List<ExpenseListItem> = emptyList()
    private lateinit var adapter: ArrayAdapter<ExpenseListItem>

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {

        _binding = FragmentFirstBinding.inflate(inflater, container, false)


        listView = binding.listView
        listView.emptyView = binding.emptyView
        adapter = object : ArrayAdapter<ExpenseListItem>(
            requireContext(),
            R.layout.item_expense,
            mutableListOf()
        ) {
            override fun getView(position: Int, convertView: View?, parent: ViewGroup): View {
                val row = convertView ?: layoutInflater.inflate(R.layout.item_expense, parent, false)
                val item = getItem(position)
                val primary = row.findViewById<TextView>(R.id.text_primary)
                val secondary = row.findViewById<TextView>(R.id.text_secondary)
                val amount = row.findViewById<TextView>(R.id.text_amount)
                if (item != null) {
                    primary.text = "${item.payee} • ${item.category}"
                    secondary.text = "${item.date} • ${item.payment}"
                    amount.text = formatAmount(item.amount)
                }
                return row
            }
        }
        listView.adapter = adapter
        binding.searchView.queryHint = getString(R.string.filter_expenses)
        binding.searchView.setOnQueryTextListener(object : SearchView.OnQueryTextListener {
            override fun onQueryTextSubmit(query: String?): Boolean {
                applyFilter(query.orEmpty())
                return true
            }

            override fun onQueryTextChange(newText: String?): Boolean {
                applyFilter(newText.orEmpty())
                return true
            }
        })
        listView.setOnItemClickListener { _, _, position, _ ->
            if (position !in filteredItems.indices) {
                return@setOnItemClickListener
            }
            val item = filteredItems[position]
            val args = Bundle().apply {
                putString(SecondFragment.ARG_DOC_ID, item.documentId)
                putString(SecondFragment.ARG_DATE, item.date)
                putString(SecondFragment.ARG_AMOUNT, item.amount)
                putString(SecondFragment.ARG_PAYEE, item.payee)
                putString(SecondFragment.ARG_CATEGORY, item.category)
                putString(SecondFragment.ARG_PAYMENT, item.payment)
                putString(SecondFragment.ARG_DESCRIPTION, item.description)
                putString(SecondFragment.ARG_REFERENCE, item.reference)
            }
            findNavController().navigate(
                R.id.action_FirstFragment_to_SecondFragment,
                args
            )
        }
        binding.fab.setOnClickListener { _ ->
            // move to the second fragment for adding
            findNavController().navigate(R.id.action_FirstFragment_to_SecondFragment)
        }

        return binding.root

    }

    override fun onResume() {
        super.onResume()
        loadExpenses()
    }

    private fun loadExpenses() {
        val db = Firebase.firestore
        db.collection("expenses")
            .get()
            .addOnSuccessListener { result ->
                allItems = result.documents.map { document ->
                    ExpenseListItem(
                        documentId = document.id,
                        date = document.getString("date").orEmpty(),
                        amount = document.get("amount")?.toString().orEmpty(),
                        payee = document.getString("payee").orEmpty(),
                        category = document.getString("category").orEmpty(),
                        payment = document.getString("payment").orEmpty(),
                        description = document.getString("description").orEmpty(),
                        reference = document.getString("reference").orEmpty()
                    )
                }
                applyFilter(binding.searchView.query?.toString().orEmpty())
            }
            .addOnFailureListener { exception ->
                println("Error getting documents: $exception")
            }
    }

    private fun applyFilter(query: String) {
        val normalizedQuery = query.trim().lowercase()
        filteredItems = if (normalizedQuery.isBlank()) {
            allItems
        } else {
            allItems.filter { item ->
                item.payee.lowercase().contains(normalizedQuery) ||
                    item.category.lowercase().contains(normalizedQuery) ||
                    item.payment.lowercase().contains(normalizedQuery) ||
                    item.description.lowercase().contains(normalizedQuery) ||
                    item.reference.lowercase().contains(normalizedQuery) ||
                    item.date.lowercase().contains(normalizedQuery) ||
                    item.amount.lowercase().contains(normalizedQuery)
            }
        }
        adapter.clear()
        adapter.addAll(filteredItems)
        adapter.notifyDataSetChanged()
    }

    private fun formatAmount(rawAmount: String): String {
        val numeric = rawAmount.toDoubleOrNull()
        return if (numeric != null) {
            String.format(Locale.getDefault(), "$%.2f", numeric)
        } else {
            "$$rawAmount"
        }
    }

    data class ExpenseListItem(
        val documentId: String,
        val date: String,
        val amount: String,
        val payee: String,
        val category: String,
        val payment: String,
        val description: String,
        val reference: String
    )

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }
}
