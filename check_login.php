<?php
include("db_connect.php");
session_start();

if(isset($_POST['login']))
{
    $user=mysqli_real_escape_string($con,$_POST['username']);
    $pass=mysqli_real_escape_string($con,$_POST['password']);

    $query="SELECT * FROM login WHERE username='$user' AND password='$pass'";
    $result=mysqli_query($con,$query);
    if($result&&mysqli_num_rows($result)>0)
    {
        $_SESSION['admin']=$user;
        echo "<script>alert('login successful');</script>";
        echo"<script>window.location.href='admin_home.php';</script>";
        exit;
    }

else
    {
    echo"<script>alert('invalid username or password!!!');</script>";
    echo"<script>window.location.href='login.php';</script>";
    exit;

    }
}
else
    {
    header("location:login.php");
    exit;
    }
?>