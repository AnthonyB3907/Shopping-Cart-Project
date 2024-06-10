document.addEventListener("DOMContentLoaded", function() {
    var viewCart = document.getElementById("viewCart");
    if (viewCart) {
        viewCart.addEventListener("click", displayCartForUser);
    }

    var goBackBtn = document.getElementById("goBackBtn");
    if (goBackBtn) {
        goBackBtn.addEventListener("click", function() {
            // Get the referrer URL from a hidden input field
            var referrer = document.getElementById("referrer").value;
            window.location.href = referrer;
        });
    }
    
    var cartContainer = document.getElementById("cartContainer");
    if (cartContainer) {
        cartContainer.addEventListener("click", function(event) {
            if (event.target.classList.contains("close-btn")) {
                cartContainer.style.display = "none";
            }
        });
    }
});

function addToCart(name, price, quantity, category) {
    let userId = getUserId();
    let userCartKey = `cart_${userId}`;

    let userCart = [];
    let cartData = localStorage.getItem(userCartKey);
    console.log('Cart data before parsing:', cartData);

    if (cartData) {
        try {
            userCart = JSON.parse(cartData);
        } catch (e) {
            console.error('Error parsing JSON from localStorage:', e);
        }
    } else {
        console.warn('No cart data found in localStorage for key:', userCartKey);
    }

    let existingItem = userCart.find(item => item.name === name && item.price === price && item.category === category);
    if (existingItem) {
        existingItem.quantity += quantity;
    } else {
        userCart.push({ name, price, quantity, category });
    }

    localStorage.setItem(userCartKey, JSON.stringify(userCart));

    console.log("Adding to cart:", name, price, quantity, category);
    showFeedbackMessage(`${name} added to cart.`);
}

function getUserId() {
    return document.getElementById('user_id').value; // Assuming user_id is set in a hidden input
}

function displayCartForUser() {
    let userId = getUserId();
    let userCartKey = `cart_${userId}`;
    let userCart = JSON.parse(localStorage.getItem(userCartKey)) || [];

    let cartContainer = document.getElementById("cartContainer");
    if (!cartContainer) {
        console.error("cartContainer element not found.");
        return;
    }

    cartContainer.innerHTML = '<button class="close-btn" onclick="closeCart()">X</button>';

    if (userCart.length === 0) {
        cartContainer.innerHTML += '<p>Your cart is empty.</p>';
    } else {
        let cartList = document.createElement('ul');
        cartList.className = 'cart-list';
        let grandTotal = 0;
        userCart.forEach((item, index) => {
            let total = (item.price * item.quantity).toFixed(2);
            grandTotal += parseFloat(total);
            let listItem = document.createElement('li');
            listItem.className = 'cart-item';
            listItem.innerHTML = `
                <span>${item.name} - $${item.price} x <input type="text" value="${item.quantity}" class="quantity-input-cart" readonly> = $${total}</span>
                <div class="cart-buttons">
                    <button class="quantity-btn" onclick="changeCartQuantity(${index}, 1)">+</button>
                    <button class="quantity-btn" onclick="changeCartQuantity(${index}, -1)">-</button>
                    <button class="remove-btn" onclick="removeCartItem(${index})">🗑️</button>
                </div>
            `;
            cartList.appendChild(listItem);
        });
        cartContainer.appendChild(cartList);

        // Display grand total
        let totalDisplay = document.createElement('p');
        totalDisplay.className = 'cart-total';
        totalDisplay.innerHTML = `Grand Total: $${grandTotal.toFixed(2)}`;
        cartContainer.appendChild(totalDisplay);

        let checkoutBtn = document.createElement('button');
        checkoutBtn.id = "checkoutBtn";
        checkoutBtn.textContent = "Checkout";
        checkoutBtn.addEventListener("click", function() {
            checkout();
        });
        cartContainer.appendChild(checkoutBtn);
    }

    cartContainer.style.display = 'block';
}

function closeCart() {
    document.getElementById("cartContainer").style.display = 'none';
}



function changeCartQuantity(index, delta) {
    let userId = getUserId();
    let userCartKey = `cart_${userId}`;

    let userCart = JSON.parse(localStorage.getItem(userCartKey)) || [];
    if (userCart[index]) {
        userCart[index].quantity += delta;
        if (userCart[index].quantity < 1) {
            userCart[index].quantity = 1;
        }
        localStorage.setItem(userCartKey, JSON.stringify(userCart));
        displayCartForUser();
    }
}

function removeCartItem(index) {
    let userId = getUserId();
    let userCartKey = `cart_${userId}`;

    let userCart = JSON.parse(localStorage.getItem(userCartKey)) || [];
    if (userCart[index]) {
        userCart.splice(index, 1);
        localStorage.setItem(userCartKey, JSON.stringify(userCart));
        displayCartForUser();
    }
}

function checkout() {
    // Redirect to checkout.php
    window.location.href = 'checkout.php';
}

function showFeedbackMessage(message) {
    const feedbackMessage = document.getElementById('feedbackMessage');
    feedbackMessage.textContent = message;
    feedbackMessage.style.display = 'block';
    setTimeout(() => {
        feedbackMessage.style.display = 'none';
    }, 3000); // Hide message after 3 seconds
}
