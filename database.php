<<?php
echo "Name is ".$_GET["abc"]."<br><br>";
echo "roll no is ".$_GET["no"]."<br><br>";

// Assign the GET values to variables (needed for your INSERT query)
$no = $_GET["no"];
$name = $_GET["abc"];

$con = mysqli_connect("localhost","root","","student");
if($con)
    echo "success";
else
    echo "failed";

$s2 = "INSERT INTO stud values($no,'$name')";
mysqli_query($con, $s2);
?>
