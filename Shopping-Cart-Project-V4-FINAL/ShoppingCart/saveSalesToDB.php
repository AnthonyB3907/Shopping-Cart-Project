<?php
session_start();
include "ScartDB.php";

// Ensure the user is logged in
if (!isset($_SESSION['id_user'])) {
    echo json_encode(['status' => 'error', 'message' => 'User not logged in']);
    exit;
}

// Get the raw POST data
$rawData = file_get_contents('php://input');
error_log("Raw POST data: " . $rawData); // Log the raw POST data for debugging
$data = json_decode($rawData, true);

// Check if cart data is sent
if (!isset($data['cart'])) {
    echo json_encode(['status' => 'error', 'message' => 'No cart data received']);
    exit;
}

// Decode the cart data
$cart = $data['cart'];

// Connect to the database
$item_db = new ScartDB();
$item_db->connect();
$dbConnection = $item_db->getDbConnection();

foreach ($cart as $item) {
    $name = $item['name'];
    $price = $item['price'] * $item['quantity']; // Calculate total price
    $category = $item['category']; // Assuming you also store category in local storage

    // Check if the item already exists in the sales table
    $query = "SELECT price FROM sales WHERE category = ? AND name = ?";
    $stmt = $dbConnection->prepare($query);
    $stmt->bind_param('ss', $category, $name);
    $stmt->execute();
    $stmt->store_result();
    
    if ($stmt->num_rows > 0) {
        // If item exists, update the price
        $stmt->bind_result($existingPrice);
        $stmt->fetch();
        $newPrice = $existingPrice + $price;

        $updateQuery = "UPDATE sales SET price = ? WHERE category = ? AND name = ?";
        $updateStmt = $dbConnection->prepare($updateQuery);
        $updateStmt->bind_param('dss', $newPrice, $category, $name);
        $updateStmt->execute();
        $updateStmt->close();
    } else {
        // If item does not exist, insert a new record
        $insertQuery = "INSERT INTO sales (category, price, name) VALUES (?, ?, ?)";
        $insertStmt = $dbConnection->prepare($insertQuery);
        $insertStmt->bind_param('sds', $category, $price, $name);
        $insertStmt->execute();
        $insertStmt->close();
    }

    $stmt->close();
}

$item_db->disconnect();

// Return only the JSON response
echo json_encode(['status' => 'success', 'message' => 'Order saved successfully']);
?>
