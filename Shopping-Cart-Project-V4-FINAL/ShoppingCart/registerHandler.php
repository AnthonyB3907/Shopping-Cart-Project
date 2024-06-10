<?php

session_start();

include "ScartDB.php";

$store_db = new ScartDB();

// Sanitize for security
$password = filter_input(INPUT_POST, 'password', FILTER_SANITIZE_STRING);
$username = filter_input(INPUT_POST, 'username', FILTER_SANITIZE_STRING);


if (!preg_match('/^[a-zA-Z].{3,}$/', $username))
{
    $_SESSION["register_error"] = "Username must be at least 4 characters long and begin with a letter";
    header("Location: register.php");
    exit;
}
// Validate Password
if (!preg_match('/^(?=.*\d).{5,}$/', $password))
{
    $_SESSION["register_error"] = "Password must contain at least 5 characters and one or more numbers";
    header("Location: register.php");
    exit;
}

// Check if user is already in the database
$store_db->connect();
$exists = $store_db->checkUserExists($username);
$store_db->disconnect();
if ($exists) {
    $_SESSION["register_error"] = "A user with that name already exists";
    header("Location: register.php");
    exit;
}

// Validate password
if (!$password) {  //TODO: Could use some extra validation
    $_SESSION["register_error"] = "Bad password";
    header("Location: CreateAccount.php");
    exit;
}

// Store user data
$password_hashed = password_hash($password, PASSWORD_DEFAULT);  // Hash password for security
$store_db->connect();
$store_db->addUser($username, $password_hashed);
$store_db->disconnect();

$_SESSION["register_success"] = true;
header("Location: register.php");

 