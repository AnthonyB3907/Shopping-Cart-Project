<?php
    session_start();
?>

<!DOCTYPE html>
<html>
    <head>
        <title>Create Account</title>
        <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
        <link rel="stylesheet" href="errors.css">
        <link rel="stylesheet" href="styles.css">
        <script>
        function redirect()
        {
            window.location.href = "home.php";
        }
        </script>
    </head>
    <body>
        
        <h1>Create Account</h1>
        
        <div>
            <form action="registerHandler.php" method="post">
                Username
                <br><br>
                <input type="text" name="username" required>
                <br><br>
                Password
                <br><br>
                <input type="password" name="password" required>
                <br><br>
                <input type="submit" value="Submit">
                <br><br>
                <button onclick="redirect()">Back to Log In</button>
                <span id="error"><?php echo isset($_SESSION['register_error']) ? $_SESSION['register_error'] : "";?></span>
            </form>
        </div>
        
        <div id="registered">
            <br><br>
            <?php echo isset($_SESSION['register_success']) ? "Successfully registered" : "";?>
        </div>
        
    </body>
</html>