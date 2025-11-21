<?php
session_start();

$con = mysqli_connect("localhost", "root", "", "student");

if (!$con) {
    die("Database connection failed");
}

// When form is submitted
if (isset($_POST['login'])) {

    $user = mysqli_real_escape_string($con, $_POST['username']);
    $pass = mysqli_real_escape_string($con, $_POST['password']);

    $query = "SELECT * FROM login WHERE username='$user' AND password='$pass'";
    $result = mysqli_query($con, $query);

    if ($result && mysqli_num_rows($result) > 0) {
        $_SESSION['admin'] = $user;
        echo "<script>alert('Login successful'); window.location='admin_home.php';</script>";
        exit;
    } else {
        echo "<script>alert('Invalid username or password'); window.location='login.php';</script>";
        exit;
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Admin Login</title>
</head>
<body>

<h2>ADMIN LOGIN</h2>

<form method="post" action="">
    Username: <input type="text" name="username" required><br><br>
    Password: <input type="password" name="password" required><br><br>
    <input type="submit" name="login" value="Login">
</form>

</body>
</html>
