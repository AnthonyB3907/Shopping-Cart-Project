<?php
session_start();
?>

<!DOCTYPE html>
<html>
    <head>
        <title>Admin Control</title>
        <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
        <link rel="stylesheet" href="errors.css">
        <link rel="stylesheet" href="styles.css">
        <script src="adminHandler.js"></script>
        <script>
        function redirect()
        {
            window.location.href = "home.php";
        }
        </script>
    </head>
    <body>
        
        <div class="admin-container">
            <h1>Admin Control</h1>
        
            <!-- Admin menu buttons -->
            <div class="admin-buttons">
                <button onclick="location.href='viewAccounts.php'">View Accounts</button>
                <button onclick="location.href='viewItems.php'">View Items</button>
                <button onclick="location.href='viewSales.php'">View Sales</button>
                <button onclick="redirect()">Log Out</button>
            </div>
        </div>

    </body>
</html>
