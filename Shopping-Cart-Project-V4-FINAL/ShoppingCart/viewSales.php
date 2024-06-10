<?php
session_start();
include "ScartDB.php";

// Ensure the user is logged in as an admin
if (!isset($_SESSION['id_user']) || !isset($_SESSION['username']) || $_SESSION['username'] !== 'admin') {
    die('User not logged in or not an admin');
}

// Connect to the database
$item_db = new ScartDB();
$item_db->connect();
$sales = $item_db->getAllSales();
$item_db->disconnect();

// Calculate grand total
$grandTotal = 0;
foreach ($sales as $sale) {
    $grandTotal += $sale['total_sales'];
}
?>

<!DOCTYPE html>
<html>
    <head>
        <title>View Sales</title>
        <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
        <link rel="stylesheet" href="errors.css">
        <link rel="stylesheet" href="styles.css">
    </head>
    <body>
        
        <div class="admin-container">
            <h1>View Sales</h1>
        
            <!-- Grand total box -->
            <div class="grand-total-box">
                <strong>Grand Total: </strong>$<?php echo number_format($grandTotal, 2); ?>
            </div>
        
            <!-- Sales table container -->
            <div class="sales-table-container">
                <table class="sales-table">
                    <thead>
                        <tr>
                            <th>Name</th>
                            <th>Total Sales</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php foreach ($sales as $sale): ?>
                            <tr>
                                <td><?php echo htmlspecialchars($sale['name']); ?></td>
                                <td>$<?php echo number_format($sale['total_sales'], 2); ?></td>
                            </tr>
                        <?php endforeach; ?>
                    </tbody>
                </table>
            </div>
        
            <!-- Button container -->
            <div class="button-container">
                <!-- Admin Control button -->
                <button class="view-sales-button" onclick="location.href='admin.php';">Admin Control</button>
        
                <!-- Log out button -->
                <button class="view-sales-button" onclick="location.href='home.php';">Log Out</button>
            </div>
        </div>

    </body>
</html>
