<?php
$no = $_GET["rollno"];
$science = $_GET["science"];
$english = $_GET["english"];
$maths = $_GET["maths"];
$total = $science + $english+$maths;

$con = mysqli_connect("localhost", "root", "", "student");

if ($con) {
    $check = "SELECT rollno FROM mark WHERE rollno='$no'";
    $result = mysqli_query($con, $check);
    
    if (!$result) {
        die('<script>alert("Error checking roll number");</script>');
    }

    if (mysqli_num_rows($result) > 0) {
        echo '<script>alert("Roll number already exists"); document.location="markentry.php";</script>';
    } else {
        $s2 = "INSERT INTO mark (rollno, science,english, maths, total)
               VALUES ('$no', '$science', '$english', '$maths', '$total')";
        $insert = mysqli_query($con, $s2);

        if ($insert) {
            echo '<script>alert("Inserted successfully"); document.location="markentry.php";</script>';
        } else {
            echo '<script>alert("Insert failed: ' . mysqli_error($con) . '");</script>';
        }
    }
} else {
    echo '<script>alert("Database connection failed");</script>';
}
