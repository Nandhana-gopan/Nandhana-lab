<?php
$username = $_GET["user"];
$pass = $_GET["pass"];
$con = mysqli_connect("localhost", "root", "", "login");

if ($con) {
    $check = "SELECT username FROM `login` WHERE username='$username'";
    $result = mysqli_query($con, $check);
}
?>
