const API_BASE_URL = 'http://localhost:5000';

function showToast(message, type = 'info') {
    const toast = document.getElementById('toast');
    toast.textContent = message;
    toast.className = `toast show ${type}`;
    
    setTimeout(() => {
        toast.classList.remove('show');
    }, 3000);
}

async function addEntry(event) {
    event.preventDefault();
    
    const key = document.getElementById('key').value.trim();
    const value = document.getElementById('value').value.trim();
    
    if (!key || !value) {
        showToast('Please enter both key and value', 'error');
        return;
    }
    
    try {
        const response = await fetch(`${API_BASE_URL}/set`, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({ [key]: value })
        });
        
        const data = await response.json();
        
        if (response.ok) {
            showToast(`Entry "${key}" added successfully!`, 'success');
            document.getElementById('addForm').reset();
            loadAllEntries();
        } else {
            showToast(data.error || 'Failed to add entry', 'error');
        }
    } catch (error) {
        showToast('Error connecting to server. Make sure the backend is running.', 'error');
        console.error('Error:', error);
    }
}

async function searchEntry() {
    const searchKey = document.getElementById('searchKey').value.trim();
    const resultBox = document.getElementById('searchResult');
    
    if (!searchKey) {
        showToast('Please enter a key to search', 'error');
        return;
    }
    
    try {
        const response = await fetch(`${API_BASE_URL}/get/${encodeURIComponent(searchKey)}`);
        const data = await response.json();
        
        resultBox.classList.add('show');
        
        if (response.ok) {
            resultBox.className = 'result-box show success';
            resultBox.innerHTML = `
                <div class="entry-key">${searchKey}</div>
                <div class="entry-value">${data.value}</div>
            `;
        } else {
            resultBox.className = 'result-box show error';
            resultBox.textContent = data.error || 'Key not found';
        }
    } catch (error) {
        resultBox.className = 'result-box show error';
        resultBox.textContent = 'Error connecting to server';
        console.error('Error:', error);
    }
}

async function loadAllEntries() {
    const container = document.getElementById('allEntries');
    container.innerHTML = '<p class="loading">Loading entries...</p>';
    
    try {
        const response = await fetch(`${API_BASE_URL}/all`);
        const data = await response.json();
        
        if (response.ok) {
            const entries = Object.entries(data);
            
            if (entries.length === 0) {
                container.innerHTML = '<div class="empty-state">No entries yet. Add your first key-value pair!</div>';
                return;
            }
            
            container.innerHTML = entries.map(([key, value]) => `
                <div class="entry-item">
                    <div class="entry-content">
                        <div class="entry-key">${escapeHtml(key)}</div>
                        <div class="entry-value">${escapeHtml(String(value))}</div>
                    </div>
                    <button class="btn btn-danger" onclick="deleteEntry('${escapeHtml(key)}')">
                        <span class="btn-icon">🗑️</span> Delete
                    </button>
                </div>
            `).join('');
        } else {
            container.innerHTML = '<div class="empty-state">Failed to load entries</div>';
        }
    } catch (error) {
        container.innerHTML = '<div class="empty-state">Error connecting to server. Make sure the backend is running on port 5000.</div>';
        console.error('Error:', error);
    }
}

async function deleteEntry(key) {
    if (!confirm(`Are you sure you want to delete "${key}"?`)) {
        return;
    }
    
    try {
        const response = await fetch(`${API_BASE_URL}/delete/${encodeURIComponent(key)}`, {
            method: 'DELETE'
        });
        
        const data = await response.json();
        
        if (response.ok) {
            showToast(`Entry "${key}" deleted successfully!`, 'success');
            loadAllEntries();
        } else {
            showToast(data.error || 'Failed to delete entry', 'error');
        }
    } catch (error) {
        showToast('Error connecting to server', 'error');
        console.error('Error:', error);
    }
}

function escapeHtml(text) {
    const div = document.createElement('div');
    div.textContent = text;
    return div.innerHTML;
}

document.getElementById('addForm').addEventListener('submit', addEntry);
document.getElementById('searchBtn').addEventListener('click', searchEntry);
document.getElementById('refreshBtn').addEventListener('click', loadAllEntries);

document.getElementById('searchKey').addEventListener('keypress', (e) => {
    if (e.key === 'Enter') {
        searchEntry();
    }
});

loadAllEntries();
