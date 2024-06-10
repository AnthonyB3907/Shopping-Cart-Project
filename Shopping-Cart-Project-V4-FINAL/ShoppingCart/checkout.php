<?php
session_start();

// Ensure the user is logged in
if (!isset($_SESSION['id_user'])) {
    header("Location: home.php");
    exit;
}

$id_user = $_SESSION['id_user'];
?>

<!DOCTYPE html>
<html>
    <head>
        <title>Checkout</title>
        <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
        <link rel="stylesheet" href="errors.css">
        <link rel="stylesheet" href="styles.css">
        <script src="checkoutHandler.js"></script>
    </head>
    <body>
        <div class="admin-container">
            <h1>Checkout</h1>
            
            <!-- Hidden input for user ID -->
            <input type="hidden" id="user_id" value="<?php echo htmlspecialchars($id_user); ?>">
            
            <div id="checkoutContainer" class="items-table-container">
                <!-- Checkout items will be displayed here -->
            </div>
            
            <div class="button-container">
                <button id="confirmCheckoutBtn" class="view-sales-button">Confirm Checkout</button>
                <button id="cancelCheckoutBtn" class="view-sales-button" onclick="location.href='shop.php';">Cancel</button>
            </div>
        </div>
    </body>
</html>
