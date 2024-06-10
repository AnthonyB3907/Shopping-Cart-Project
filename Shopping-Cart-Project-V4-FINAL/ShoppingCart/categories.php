<?php
session_start();

include "ScartDB.php";

if (!isset($_GET['category'])) {
    die('Category not specified.');
}

$category = urldecode($_GET['category']);

$item_db = new ScartDB();
$item_db->connect();
$items = $item_db->getItemsByCategory($category);
$item_db->disconnect();

if (!isset($_SESSION['id_user'])) {
    header("Location: home.php");
    exit;
}

$id_user = $_SESSION['id_user'];
?>

<!DOCTYPE html>
<html>
    <head>
        <title>Items in <?php echo htmlspecialchars($category); ?></title>
        <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
        <link rel="stylesheet" href="errors.css">
        <link rel="stylesheet" href="styles.css">
        <script src="cartHandler.js"></script>
        <script src="categoryHandler.js"></script>
    </head>
    <body>
        <div class="categories-container">
            <h1>Items in <?php echo htmlspecialchars($category); ?></h1>

            <!-- Feedback message -->
            <div id="feedbackMessage" class="feedback-message"></div>

            <!-- List of items -->
            <form id="itemForm">
                <input type="hidden" name="category" value="<?php echo htmlspecialchars($category); ?>">
                <input type="hidden" id="user_id" value="<?php echo htmlspecialchars($id_user); ?>">
                <div class="items-table-container">
                    <table class="items-table">
                        <thead>
                            <tr>
                                <th>Name</th>
                                <th>Price</th>
                                <th>Quantity</th>
                                <th>Total Price</th>
                                <th>Add to Cart</th>
                            </tr>
                        </thead>
                        <tbody>
                            <?php foreach ($items as $item): ?>
                                <tr class="item-row">
                                    <td><input type="text" name="name[]" value="<?php echo htmlspecialchars($item['name']); ?>" class="item-input" readonly></td>
                                    <td><input type="text" name="price[]" value="<?php echo htmlspecialchars($item['price']); ?>" class="item-input" readonly></td>
                                    <td>
                                        <div class="quantity-control">
                                            <button type="button" class="quantity-button" onclick="changeItemQuantity(this, <?php echo htmlspecialchars($item['price']); ?>, -1)">-</button>
                                            <input type="text" name="quantity[]" value="1" class="quantity-input">
                                            <button type="button" class="quantity-button" onclick="changeItemQuantity(this, <?php echo htmlspecialchars($item['price']); ?>, 1)">+</button>
                                        </div>
                                    </td>
                                    <td class="item-price">$<?php echo htmlspecialchars($item['price']); ?></td>
                                    <td><button type="button" class="add-to-cart-button" onclick="addToCart('<?php echo htmlspecialchars($item['name']); ?>', <?php echo htmlspecialchars($item['price']); ?>, parseInt(this.parentElement.parentElement.querySelector('.quantity-input').value), '<?php echo htmlspecialchars($item['category']); ?>')">Add to Cart</button></td>
                                </tr>
                            <?php endforeach; ?>
                        </tbody>
                    </table>
                </div>
            </form>

            <!-- Button container -->
            <div class="button-container">
                <button class="categories-button" type="button" id="viewCart">View Cart</button>
                <button class="categories-button" type="button" onclick="location.href='shop.php';">Return to Store</button>
            </div>
        </div>
        <div id="cartContainer"></div>
    </body>
</html>
