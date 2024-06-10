document.addEventListener("DOMContentLoaded", function() {
    displayCheckoutItems();
    
    var confirmCheckoutBtn = document.getElementById("confirmCheckoutBtn");
    if (confirmCheckoutBtn) {
        confirmCheckoutBtn.addEventListener("click", function(event) {
            event.preventDefault();
            confirmCheckout();
        });
    }
});

function getUserId() {
    const userIdElement = document.getElementById('user_id');
    if (!userIdElement) {
        console.error('User ID element not found.');
        return null;
    }
    return userIdElement.value;
}

function displayCheckoutItems() {
    let userId = getUserId();
    if (!userId) {
        return; // Exit if user ID is not found
    }
    let userCartKey = `cart_${userId}`;
    let userCart = JSON.parse(localStorage.getItem(userCartKey)) || [];

    let checkoutContainer = document.getElementById("checkoutContainer");
    if (!checkoutContainer) {
        console.error("checkoutContainer element not found.");
        return;
    }

    checkoutContainer.innerHTML = '';

    if (userCart.length === 0) {
        checkoutContainer.innerHTML = '<p>Your cart is empty.</p>';
    } else {
        let cartList = document.createElement('table');
        cartList.classList.add('items-table');
        let grandTotal = 0;
        cartList.innerHTML = `
            <thead>
                <tr>
                    <th>Name</th>
                    <th>Price</th>
                    <th>Quantity</th>
                    <th>Total</th>
                </tr>
            </thead>
            <tbody>
        `;
        userCart.forEach((item) => {
            let total = (item.price * item.quantity).toFixed(2);
            grandTotal += parseFloat(total);
            cartList.innerHTML += `
                <tr>
                    <td>${item.name}</td>
                    <td>$${item.price}</td>
                    <td>${item.quantity}</td>
                    <td>$${total}</td>
                </tr>
            `;
        });
        cartList.innerHTML += `
            <tr>
                <td colspan="3" class="grand-total">Grand Total:</td>
                <td>$${grandTotal.toFixed(2)}</td>
            </tr>
        `;
        cartList.innerHTML += `</tbody>`;
        checkoutContainer.appendChild(cartList);
    }
}

function confirmCheckout() {
    let userId = getUserId();
    if (!userId) {
        return; // Exit if user ID is not found
    }
    let userCartKey = `cart_${userId}`;
    let userCart = JSON.parse(localStorage.getItem(userCartKey)) || [];

    if (userCart.length === 0) {
        alert('Your cart is empty.');
        return;
    }

    // Send cart data to the server
    fetch('saveSalesToDB.php', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ cart: userCart })
    })
    .then(response => response.text()) // Use text() to see the raw response
    .then(data => {
        console.log('Server response:', data); // Log the response for debugging

        try {
            let jsonData = JSON.parse(data); // Parse the response
            if (jsonData.status === 'success') {
                alert('Order confirmed! Thank you for your purchase.');
                // Clear the cart after checkout
                localStorage.removeItem(userCartKey);
                // Redirect to store page
                window.location.href = 'shop.php';
            } else {
                alert('Error: ' + jsonData.message);
            }
        } catch (e) {
            console.error('Error parsing JSON:', e);
            alert('An error occurred while processing your order.');
        }
    })
    .catch(error => {
        console.error('Error:', error);
        alert('An error occurred while processing your order.');
    });
}
