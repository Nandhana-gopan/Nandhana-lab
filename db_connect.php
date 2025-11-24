<?php
$con=mysqli_connect("localhost","root","","student");

if(!$con)
{
    die('<script>alert("database connection failed");</script>');
}
else
{
    echo'<script>alert("database connection succesful");</script';
}
?>