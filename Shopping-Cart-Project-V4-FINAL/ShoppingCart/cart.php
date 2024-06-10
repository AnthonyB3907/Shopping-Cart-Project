<?php
session_start();
$referrer = isset($_GET['referrer']) ? urldecode($_GET['referrer']) : 'home.php';
$id_user = $_SESSION['id_user'];
?>

<!DOCTYPE html>
<html>
    <head>
        <title>Your Cart</title>
        <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
        <link rel="stylesheet" href="errors.css">
        <link rel="stylesheet" href="styles.css">
        <script src="cartHandler.js"></script>
    </head>
    <body>
        <input type="hidden" id="user_id" value="<?php echo htmlspecialchars($id_user); ?>">
        <input type="hidden" id="referrer" value="<?php echo htmlspecialchars($referrer); ?>">

        <h1>Your Cart</h1>
        <div id="cartContainer">
            <button id="checkoutBtn">Checkout</button>
            <!-- Cart items will be displayed here -->
        </div>

        <button id="goBackBtn">Go Back</button>
    </body>
</html>
