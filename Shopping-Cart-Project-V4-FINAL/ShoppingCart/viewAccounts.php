<?php
session_start();
include "ScartDB.php";

// Fetch all users from the database
$item_db = new ScartDB();
$item_db->connect();
$users = $item_db->getAllUsers();
$item_db->disconnect();
?>

<!DOCTYPE html>
<html>
    <head>
        <title>Edit Accounts</title>
        <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
        <link rel="stylesheet" href="errors.css">
        <link rel="stylesheet" href="styles.css">
        <script src="adminHandler.js"></script>
    </head>
    <body>
        
        <div class="admin-container">
            <h1>View Accounts</h1>
        
            <!-- List of users with edit buttons -->
            <div id="userList" class="user-list">
                <?php foreach ($users as $user): ?>
                    <div class="user-item">
                        <input type="text" name="username" value="<?php echo htmlspecialchars($user['username']); ?>" data-id="<?php echo $user['id_user']; ?>">
                        <input type="password" name="password" placeholder="New Password" data-id="<?php echo $user['id_user']; ?>">
                    </div>
                <?php endforeach; ?>
            </div>
        
            <!-- Button container -->
            <div class="button-container">
                <!-- Save button -->
                <button class="view-accounts-button" id="saveUsersBtn">Save Changes</button>
        
                <!-- Admin Control button -->
                <button class="view-accounts-button" onclick="location.href='admin.php';">Admin Control</button>
        
                <!-- Log out button -->
                <button class="view-accounts-button" onclick="redirect()">Log Out</button>
            </div>
        </div>
    </body>
</html>
