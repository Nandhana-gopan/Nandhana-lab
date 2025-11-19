<?php
$con = mysqli_connect("localhost", "root", "", "student");

if (!$con) {
    die("Database connection failed");
}

// If update button clicked from table
if (isset($_POST['rollno'])) {
    $roll = $_POST['rollno'];

    $query = mysqli_query($con, "SELECT * FROM studreg WHERE rollno='$roll'");
    $row = mysqli_fetch_assoc($query);
}

// If update form submitted
if (isset($_POST['save'])) {

    $roll = $_POST['rollno'];
    $address = $_POST['address'];
    $phone = $_POST['phone'];

    $update = "UPDATE studreg SET address='$address', phone='$phone' WHERE rollno='$roll'";
    mysqli_query($con, $update);

    echo "<script>alert('Record Updated Successfully'); window.location='student_view.php';</script>";
    exit;
}

?>

<h2>Update Student Details</h2>

<form method="post">
    Roll No: <b><?= $row['rollno']; ?></b><br><br>
    Name: <b><?= $row['name']; ?></b><br><br>

    Address:<br>
    <input type="text" name="address" value="<?= $row['address']; ?>" required><br><br>

    Phone:<br>
    <input type="text" name="phone" value="<?= $row['phone']; ?>" required><br><br>

    <input type="hidden" name="rollno" value="<?= $row['rollno']; ?>">

    <input type="submit" name="save" value="Save Changes">
</form>

<?php mysqli_close($con); ?>
