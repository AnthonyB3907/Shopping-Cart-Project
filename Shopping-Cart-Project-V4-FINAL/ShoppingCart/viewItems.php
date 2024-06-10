<?php
session_start();
include "ScartDB.php";

// Fetch all categories from the database
$item_db = new ScartDB();
$item_db->connect();
$categories = $item_db->getCategories();
$item_db->disconnect();
?>

<!DOCTYPE html>
<html>
    <head>
        <title>View Items</title>
        <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
        <link rel="stylesheet" href="errors.css">
        <link rel="stylesheet" href="styles.css">
    </head>
    <body>
        
        <div class="admin-container">
            <h1>View Items</h1>
        
            <!-- Category buttons -->
            <div class="categories">
                <?php foreach ($categories as $category): ?>
                    <form action="fetchItems.php" method="POST" style="display: inline;">
                        <input type="hidden" name="category" value="<?php echo htmlspecialchars($category['category']); ?>">
                        <button type="submit" class="categoryBtn">
                            <div class="category-content">
                                <?php echo htmlspecialchars($category['category']); ?>
                            </div>
                        </button>
                    </form>
                <?php endforeach; ?>
            </div>
        
            <!-- Button container -->
            <div class="button-container">
                <!-- Admin Control button -->
                <button class="view-items-button" onclick="location.href='admin.php';">Admin Control</button>
        
                <!-- Log out button -->
                <button class="view-items-button" onclick="location.href='home.php';">Log Out</button>
            </div>
        </div>

    </body>
</html>
