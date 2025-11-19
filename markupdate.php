<?php
$con = mysqli_connect("localhost", "root", "", "student");
if (!$con) {
    die('<script>alert("Database connection failed");</script>');
}

$check = "SELECT rollno FROM mark";
$result = mysqli_query($con, $check);
?>

<form action="" method="post">
    <label for="roll">Roll No:</label>
    <select name="rollno" id="roll" required>
        <option value="">Select roll no</option>
        <?php
        while ($row = mysqli_fetch_assoc($result)) {
            echo '<option value="' . $row['rollno'] . '">' . $row['rollno'] . '</option>';
        }
        ?>
    </select>
    <input type="submit" name="show" value="Show Details">
</form>

<?php
if (isset($_POST['show']) && !empty($_POST['rollno'])) {
    $roll = $_POST['rollno'];
    $query = "SELECT * FROM mark WHERE rollno='$roll'";
    $queryresult = mysqli_query($con, $query);

    if ($row = mysqli_fetch_assoc($queryresult)) {
        echo "<h3>Student Details</h3>";
        echo "Roll no: " . $row['rollno'] . "<br>";
        echo "<form method='post'>";
        echo "science: <input type='number' name='newmark1' value='" . $row['science'] . "' required><br>";
        echo "english: <input type='number' name='newmark2' value='" . $row['english'] . "' required><br>";
        echo "maths: <input type='number' name='newmark3' value='" . $row['maths'] . "' required><br>";
        echo "<input type='hidden' name='rollno' value='" . $row['rollno'] . "'>";
        echo "<input type='submit' name='update' value='Update Marks'>";
        echo "</form>";
    } else {
        echo "No record found";
    }
}
if (isset($_POST['update'])) {
    $roll = $_POST['rollno'];
    $newmark1 = $_POST['newmark1'];
    $newmark2 = $_POST['newmark2'];
    $newmark3 = $_POST['newmark3'];

    //$getmarks = mysqli_query($con, "SELECT mark2 FROM stud WHERE rollno='$roll'");
    //if ($marks = mysqli_fetch_assoc($getmarks)) {
        //$mark2 = $marks['mark2'];
        $total = $newmark1 + $newmark2+$newmark3;

        $updateQuery = "UPDATE mark SET science='$newmark1',english='$newmark2',maths='$newmark3' ,total='$total' WHERE rollno='$roll'";
        $updateResult = mysqli_query($con, $updateQuery);

        if ($updateResult) {
            echo "<script>alert('Marks updated successfully!');</script>";
        } else {
            echo "<script>alert('Update failed: " . mysqli_error($con) . "');</script>";
        }
    }


mysqli_close($con);
?>
