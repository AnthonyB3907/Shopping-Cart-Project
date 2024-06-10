<?php
session_start();
include "ScartDB.php";

// Ensure the user is logged in as an admin
if (!isset($_SESSION['id_user']) || !isset($_SESSION['username']) || $_SESSION['username'] !== 'admin') {
    die('User not logged in or not an admin');
}

if (!isset($_POST['category'])) {
    die('No category received');
}

$category = $_POST['category'];

// Connect to the database
$item_db = new ScartDB();
$item_db->connect();
$items = $item_db->getItemsByCategory($category);
$item_db->disconnect();
?>

<!DOCTYPE html>
<html>
    <head>
        <title>Items in <?php echo htmlspecialchars($category); ?></title>
        <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
        <link rel="stylesheet" href="errors.css">
        <link rel="stylesheet" href="styles.css">
        <script src="adminHandler.js"></script>
    </head>
    <body>
        <div class="admin-container">
            <h1>Items in <?php echo htmlspecialchars($category); ?></h1>
        
            <!-- List of items -->
            <form id="itemForm">
                <input type="hidden" name="category" value="<?php echo htmlspecialchars($category); ?>">
                <div class="items-table-container">
                    <table class="items-table">
                        <thead>
                            <tr>
                                <th>Name</th>
                                <th>Price</th>
                                <th>Quantity</th>
                                <th>Add to Cart</th>
                            </tr>
                        </thead>
                        <tbody>
                            <?php foreach ($items as $item): ?>
                                <tr class="item-row">
                                    <td><input type="text" name="name[]" value="<?php echo htmlspecialchars($item['name']); ?>" class="item-input"></td>
                                    <td><input type="text" name="price[]" value="<?php echo htmlspecialchars($item['price']); ?>" class="item-input"></td>
                                    <input type="hidden" name="id[]" value="<?php echo htmlspecialchars($item['id_item']); ?>">
                                    <td>
                                        <div class="quantity-control">
                                            <button type="button" class="quantity-button" onclick="changeItemQuantity(this, <?php echo htmlspecialchars($item['price']); ?>, -1)">-</button>
                                            <input type="text" name="quantity[]" value="1" class="quantity-input">
                                            <button type="button" class="quantity-button" onclick="changeItemQuantity(this, <?php echo htmlspecialchars($item['price']); ?>, 1)">+</button>
                                        </div>
                                    </td>
                                    <td><button type="button" class="add-to-cart-button" onclick="addToCart('<?php echo htmlspecialchars($item['name']); ?>', <?php echo htmlspecialchars($item['price']); ?>, parseInt(this.parentElement.parentElement.querySelector('.quantity-input').value), '<?php echo htmlspecialchars($item['category']); ?>')">Add to Cart</button></td>
                                </tr>
                            <?php endforeach; ?>
                        </tbody>
                    </table>
                </div>
                <div class="button-container">
                    <button class="fetch-items-button" type="submit">Save Changes</button>
                    <button class="fetch-items-button" type="button" onclick="history.back()">Back</button>
                    <button class="fetch-items-button" type="button" onclick="location.href='admin.php';">Admin Control</button>
                </div>
            </form>
        
            <!-- Message display area -->
            <div id="message"></div>
        </div>
    </body>
</html>
