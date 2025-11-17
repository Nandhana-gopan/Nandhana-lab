<?php
$con = mysqli_connect("localhost", "root", "", "student");
if (!$con) {
    die('<script>alert("Database connection failed");</script>');
}

$check = "SELECT rollno FROM stud";
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
    $query = "SELECT * FROM stud WHERE rollno='$roll'";
    $queryresult = mysqli_query($con, $query);

    if ($row = mysqli_fetch_assoc($queryresult)) {
        echo "<h3>Student Details</h3>";
        echo "Roll no: " . $row['rollno'] . "<br>";
        echo "Name: " . $row['Name'] . "<br>";
        echo "Gender: " . $row['gender'] . "<br>";
        echo "<form method='post'>";
        echo "Mark1: <input type='number' name='newmark1' value='" . $row['mark1'] . "' required><br>";
        echo "Mark2: " . $row['mark2'] . "<br>";
        echo "Total: " . $row['total'] . "<br>";
        echo "<input type='hidden' name='rollno' value='" . $row['rollno'] . "'>";
        echo "<input type='submit' name='update' value='Update Mark1'>";
        echo "</form>";
    } else {
        echo "No record found";
    }
}

if (isset($_POST['update'])) {
    $roll = $_POST['rollno'];
    $newmark1 = $_POST['newmark1'];

    $getmarks = mysqli_query($con, "SELECT mark2 FROM stud WHERE rollno='$roll'");
    if ($marks = mysqli_fetch_assoc($getmarks)) {
        $mark2 = $marks['mark2'];
        $total = $newmark1 + $mark2;

        $updateQuery = "UPDATE student1 SET mark1='$newmark1', total='$total' WHERE rollno='$roll'";
        $updateResult = mysqli_query($con, $updateQuery);

        if ($updateResult) {
            echo "<script>alert('Mark1 updated successfully!');</script>";
        } else {
            echo "<script>alert('Update failed: " . mysqli_error($con) . "');</script>";
        }
    }
}

mysqli_close($con);
?>
