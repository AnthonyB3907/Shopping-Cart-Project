<?php
session_start();

include "ScartDB.php";

$store_db = new ScartDB();

// Sanitize for security
$username = filter_input(INPUT_POST, 'username', FILTER_SANITIZE_STRING);
$password = filter_input(INPUT_POST, 'password', FILTER_SANITIZE_STRING);

//echo "email: ".$email."<br>";  //DEBUG
//echo "PASSWORD: ".$password."<br>";  //DEBUG
 
// Verify user credentials
$store_db->connect();
$userdata = $store_db->getUser($username);
$store_db->disconnect();     

if ($userdata === false) {
    $_SESSION["login_error"] = "Invalid username";
    header("Location: home.php");
    exit;
}

if (!($userdata["USERNAME"] == $username && password_verify($password, $userdata["PASSWORD"]))) {
    $_SESSION["login_error"] = "Invalid username or password";
    header("Location: home.php");
   exit;
}

$_SESSION['id_user'] = $userdata['USER_UID'];
$_SESSION['username'] = $userdata['USERNAME']; // Ensure username is set

if (($userdata["USERNAME"] == "admin" && password_verify($password, $userdata["PASSWORD"])))
{
    header("Location: admin.php");
    exit;
}
else
{
    header("Location: shop.php");
}

// Login redirect
// $_SESSION["login_error"] = "WOHOO! PASSWORD VERIFIED!";  //DEBUG
// header("Location: home.php");  //DEBUG
// header("Location: User.php");  //NOT IMPLEMENTED