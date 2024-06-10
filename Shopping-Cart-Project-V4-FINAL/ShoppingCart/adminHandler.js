document.addEventListener("DOMContentLoaded", function() {
    console.log("Admin handler script loaded.");

    // Handle save button click for users
    document.getElementById('saveUsersBtn')?.addEventListener('click', function() {
        saveUserChanges();
    });

    // Handle save button click for items
    document.getElementById('saveItemsBtn')?.addEventListener('click', function() {
        saveItemChanges();
    });

    // Handle category button clicks in viewItems.php
    document.querySelectorAll('.category')?.forEach(function(button) {
        button.addEventListener('click', function(event) {
            event.preventDefault();
            let category = this.getAttribute('data-category');
            fetchItems(category);
        });
    });
    
    // Handle save button click for items
    document.getElementById('itemForm')?.addEventListener('submit', function(event) {
        event.preventDefault();
        saveItemChanges();
    });
});

function redirect() {
    window.location.href = "home.php";
}

function saveUserChanges() {
    let users = [];
    document.querySelectorAll('.user-item').forEach(function(item) {
        let id = item.querySelector('input[name="username"]').getAttribute('data-id');
        let username = item.querySelector('input[name="username"]').value;
        let password = item.querySelector('input[name="password"]').value;
        users.push({ id, username, password });
    });

    fetch('saveUsers.php', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ users })
    })
    .then(response => response.text())
    .then(data => {
        console.log('Raw server response:', data); // Log raw response for debugging
        if (data.trim() === 'success') {
            alert('User changes saved successfully!');
        } else {
            alert('Error saving user changes: ' + data);
        }
    })
    .catch(error => {
        console.error('Error:', error);
        alert('An error occurred while saving user changes.');
    });
}

function saveItemChanges() {
    let formData = new FormData(document.getElementById('itemForm'));

    fetch('saveItems.php', {
        method: 'POST',
        body: formData
    })
    .then(response => response.text())
    .then(data => {
        console.log('Raw server response:', data); // Log raw response for debugging
        if (data.trim() === 'Changes saved successfully') {
            document.getElementById('message').innerText = 'Changes saved successfully!';
        } else {
            document.getElementById('message').innerText = 'Error saving changes: ' + data;
        }
    })
    .catch(error => {
        console.error('Error:', error);
        document.getElementById('message').innerText = 'An error occurred while saving changes.';
    });
}

function fetchItems(category) {
    fetch('fetchItems.php', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ category })
    })
    .then(response => response.json())
    .then(data => {
        if (data.status === 'success') {
            displayItems(data.items);
        } else {
            alert('Error fetching items: ' + data.message);
        }
    })
    .catch(error => {
        console.error('Error:', error);
        alert('An error occurred while fetching items.');
    });
}

function displayItems(items) {
    let itemList = document.getElementById('itemList');
    itemList.innerHTML = '';

    items.forEach(function(item) {
        let itemDiv = document.createElement('div');
        itemDiv.className = 'item';

        itemDiv.innerHTML = `
            <input type="text" name="itemName" value="${item.name}" data-id="${item.id}">
            <input type="text" name="itemPrice" value="${item.price}" data-id="${item.id}">
        `;
        itemList.appendChild(itemDiv);
    });
}
