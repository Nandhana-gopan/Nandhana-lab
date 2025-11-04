<?php
$no = $_GET["rollno"];
$name = $_GET["abc"];
$gender = $_GET["gender"];
$mark1 = $_GET["mark1"];
$mark2 = $_GET["mark2"];
$total = $mark1 + $mark2;

$con = mysqli_connect("localhost", "root", "", "student");

if ($con) {
    $check = "SELECT rollno FROM student1 WHERE rollno='$no'";
    $result = mysqli_query($con, $check);
    
    if (!$result) {
        die('<script>alert("Error checking roll number");</script>');
    }

    if (mysqli_num_rows($result) > 0) {
        echo '<script>alert("Roll number already exists"); document.location="web13.php";</script>';
    } else {
        $s2 = "INSERT INTO student1 (rollno, name, gender, mark1, mark2, total)
               VALUES ('$no', '$name', '$gender', '$mark1', '$mark2', '$total')";
        $insert = mysqli_query($con, $s2);

        if ($insert) {
            echo '<script>alert("Inserted successfully"); document.location="web13.php";</script>';
        } else {
            echo '<script>alert("Insert failed: ' . mysqli_error($con) . '");</script>';
        }
    }
} else {
    echo '<script>alert("Database connection failed");</script>';
}
