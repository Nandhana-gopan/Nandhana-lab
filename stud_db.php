<?php
$no = $_GET["rollno"];
echo "Roll number received: $no<br>";
$name = $_GET["abc"];
$phone = $_GET["number"];
$address = $_GET["address"];
$user = $_GET["user"];
$pass = $_GET["pass"];

$con = mysqli_connect("localhost", "root", "", "student");

if ($con) {
    $check = "SELECT rollno FROM studreg WHERE rollno='$no'";
    $result = mysqli_query($con, $check);
    
    if (!$result) {
        die('<script>alert("Error checking roll number");</script>');
    }

    if (mysqli_num_rows($result) > 0) {
        echo '<script>alert("Roll number already exists"); document.location="studentreg.php";</script>';
    } else {
        $s2 = "INSERT INTO studreg (rollno, name,phone,address,username,password)
               VALUES ('$no', '$name', '$phone', '$address', '$user', '$pass')";
        $insert = mysqli_query($con, $s2);

        if ($insert) {
            echo '<script>alert("Inserted successfully"); document.location="stud_db.php";</script>';
        } else {
            echo '<script>alert("Insert failed: ' . mysqli_error($con) . '");</script>';
        }
    }
} else {
    echo '<script>alert("Database connection failed");</script>';
}
