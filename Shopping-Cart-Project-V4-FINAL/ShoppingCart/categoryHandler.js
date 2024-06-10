function updateQuantity(element, price) {
    const quantityInput = element.closest('.quantity-control').querySelector('.quantity-input');
    const quantity = parseInt(quantityInput.value);
    const priceElement = element.closest('.item-row').querySelector('.item-price');
    const totalPrice = (quantity * price).toFixed(2);
    priceElement.textContent = `$${totalPrice}`;
}

function changeItemQuantity(button, price, increment) {
    const quantityInput = button.closest('.quantity-control').querySelector('.quantity-input');
    let quantity = parseInt(quantityInput.value);
    quantity = isNaN(quantity) ? 0 : quantity;
    quantity += increment;
    quantity = quantity < 1 ? 1 : quantity;
    quantityInput.value = quantity;
    updateQuantity(button, price);
}
