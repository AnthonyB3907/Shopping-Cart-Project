<?php
    session_start();

include "ScartDB.php";

$item_db = new ScartDB();

$item_db->connect();
$cats = $item_db->getCategories();
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
        <title>Anthony's Shop</title>
        <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
        <link rel="stylesheet" href="errors.css">
        <link rel="stylesheet" href="styles.css">
        <script src="cartHandler.js"></script>
    </head>
    <body>
        <div class="shop-container">
            <input type="hidden" id="user_id" value="<?php echo htmlspecialchars($id_user); ?>">
            <h1>Anthony's Shop</h1>
        
            <div class="categories">
                <?php foreach ($cats as $category): ?>
                    <a href="categories.php?category=<?php echo urlencode($category['category']); ?>" class="category">
                        <div class="category-content">
                            <?php echo htmlspecialchars($category['category']); ?>
                        </div>
                    </a>
                <?php endforeach; ?>
            </div>
        
            <!-- Button container -->
            <div class="button-container">
                <!-- View Cart Button -->
                <button class="shop-button" id="viewCart">View Cart</button>
        
                <!-- Log Out Button -->
                <button class="shop-button" onclick="location.href='home.php';">Log Out</button>
            </div>
        
            <!-- Cart container for displaying cart items -->
            <div id="cartContainer"></div>
        </div>
    </body>
</html>
