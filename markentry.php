<?php
$con = mysqli_connect("localhost", "root", "", "student");
if (!$con) {
    die('<script>alert("Database connection failed");</script>');
}

$check = "SELECT rollno FROM studreg";
$result = mysqli_query($con, $check);
?>

<form action="markentrydb.php" method="get">
    <label for="roll">Roll No:</label>
    <select name="rollno" id="roll" required>
        <option value="">Select roll no</option>
        <?php
        while ($row = mysqli_fetch_assoc($result)) {
            echo '<option value="' . $row['rollno'] . '">' . $row['rollno'] . '</option>';
        }
        ?>
    </select><br><br>
    science<input type="text" name="science"><br><br>
    english<input type="text" name="english"><br><br>
    maths<input type="text" name="maths"><br><br>
    <input type="submit">
    <input type="reset">
</form>