<?php
    session_start();
?>

<!DOCTYPE html>
<html>
    <head>
        <title>Anthony's Store</title>
        <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
        <link rel="stylesheet" href="errors.css">
        <link rel="stylesheet" href="styles.css">
    </head>

    <body>
        <div class="center-container">
            <h1>Anthony's Store</h1>
            <h2>Log In</h2>
            <div class="login-form">
                <form action="login.php" method="post">
                    <label for="username">Username</label>
                    <input type="text" id="username" name="username" required>
                    <label for="password">Password</label>
                    <input type="password" id="password" name="password" required>
                    <input type="submit" value="Log in">
                    <span id="error"><?php echo isset($_SESSION['login_error']) ? $_SESSION['login_error'] : "";?></span>
                </form>
            </div>

            <div class="register">
                <h3>Register an account</h3>
                <button type="button" onclick="location.href='register.php'">Register</button>
            </div>
        </div>
        
        <?php
            session_unset();
            session_destroy();
        ?>
        
    </body>
</html>
