<?php
session_start();
include "ScartDB.php";

// Debugging: Print session variables to ensure they are set
error_log("Session ID User: " . (isset($_SESSION['id_user']) ? $_SESSION['id_user'] : "Not set"));
error_log("Session Username: " . (isset($_SESSION['username']) ? $_SESSION['username'] : "Not set"));

// Ensure the user is logged in as an admin
if (!isset($_SESSION['id_user']) || !isset($_SESSION['username']) || $_SESSION['username'] !== 'admin') {
    echo 'User not logged in or not an admin';
    exit;
}

// Get the raw POST data
$rawData = file_get_contents('php://input');
$data = json_decode($rawData, true);

if (!isset($data['users'])) {
    echo 'No user data received';
    exit;
}

$users = $data['users'];

// Connect to the database
$item_db = new ScartDB();
$item_db->connect();
$dbConnection = $item_db->getDbConnection();

foreach ($users as $user) {
    $id = $user['id'];
    $username = $user['username'];
    $password = $user['password'];

    if (!empty($password)) {
        $password_hashed = password_hash($password, PASSWORD_DEFAULT);
        $query = "UPDATE users SET username = ?, password = ? WHERE id_user = ?";
        $stmt = $dbConnection->prepare($query);
        $stmt->bind_param('ssi', $username, $password_hashed, $id);
    } else {
        $query = "UPDATE users SET username = ? WHERE id_user = ?";
        $stmt = $dbConnection->prepare($query);
        $stmt->bind_param('si', $username, $id);
    }

    if (!$stmt->execute()) {
        echo 'Error saving changes';
        $stmt->close();
        $item_db->disconnect();
        exit;
    }

    $stmt->close();
}

$item_db->disconnect();

echo 'success';
?>
