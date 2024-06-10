<?php
session_start();
include "ScartDB.php";

// Ensure the user is logged in as an admin
if (!isset($_SESSION['id_user']) || !isset($_SESSION['username']) || $_SESSION['username'] !== 'admin') {
    die('User not logged in or not an admin');
}

if (!isset($_POST['id']) || !isset($_POST['name']) || !isset($_POST['price'])) {
    die('No item data received');
}

$ids = $_POST['id'];
$names = $_POST['name'];
$prices = $_POST['price'];

// Connect to the database
$item_db = new ScartDB();
$item_db->connect();
$dbConnection = $item_db->getDbConnection();

for ($i = 0; $i < count($ids); $i++) {
    $id = $ids[$i];
    $name = $names[$i];
    $price = $prices[$i];

    $query = "UPDATE items SET name = ?, price = ? WHERE id_item = ?";
    $stmt = $dbConnection->prepare($query);
    $stmt->bind_param('sdi', $name, $price, $id);

    if (!$stmt->execute()) {
        die('Error saving changes');
    }

    $stmt->close();
}

$item_db->disconnect();

echo 'Changes saved successfully';
?>
