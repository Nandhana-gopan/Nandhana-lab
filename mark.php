<?php
$con = mysqli_connect("localhost", "root", "", "student");
if (!$con) 
{
    die('<script>alert("Database connection failed");</script>');
}
$check = "SELECT rollno FROM student1";

