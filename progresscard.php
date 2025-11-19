<?php
$con = mysqli_connect("localhost", "root", "", "student");
if (!$con) {
    die('<script>alert("Database connection failed");</script>');
}


if (isset($_GET['top'])) {

    // Get student with highest total marks
    $query = "
        SELECT studreg.*, mark.*
        FROM studreg
        JOIN mark ON studreg.rollno = mark.rollno
        ORDER BY (mark.science + mark.english + mark.maths) DESC
        LIMIT 1
    ";

    $resultTop = mysqli_query($con, $query);

    if ($row = mysqli_fetch_assoc($resultTop)) {

        echo "<a href='progresscard.php' style='font-size:16px; text-decoration:none;'>⬅ Back</a><br><br>";

        echo "<h2 style='margin-top:10px;'>🏆 Top Scorer</h2>";

        echo "
        <table border='1' cellpadding='10' cellspacing='0' 
               style='width: 400px; border-collapse: collapse; font-size: 16px;'>
               
            <tr style='background:#ffe8b3;'>
                <th colspan='2'>Student Details</th>
            </tr>
            <tr>
                <td><b>Roll No</b></td>
                <td>{$row['rollno']}</td>
            </tr>
            <tr>
                <td><b>Name</b></td>
                <td>{$row['name']}</td>
            </tr>

            <tr style='background:#ffe8b3;'>
                <th colspan='2'>Marks</th>
            </tr>
            <tr>
                <td><b>Science</b></td>
                <td>{$row['science']}</td>
            </tr>
            <tr>
                <td><b>English</b></td>
                <td>{$row['english']}</td>
            </tr>
            <tr>
                <td><b>Maths</b></td>
                <td>{$row['maths']}</td>
            </tr>
            <tr style='background:#d8ffd8;'>
                <td><b>Total</b></td>
                <td><b>" . ($row['science'] + $row['english'] + $row['maths']) . "</b></td>
            </tr>
        </table>
        ";
    } else {
        echo "No records found";
    }

    exit; // Stop the rest of the page from loading
}

// ----------------------------
//        NORMAL PAGE
// ----------------------------
?>

<!-- Top Scorer Link -->
<a href="?top=1" style="font-size:18px; font-weight:bold; margin-bottom:20px; display:inline-block;">
 View Top Scorer
</a>

<?php
// Load roll numbers
$check = "SELECT rollno FROM studreg";
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
// ----------------------------
//   SHOW SELECTED STUDENT
// ----------------------------
if (isset($_POST['show']) && !empty($_POST['rollno'])) {
    $roll = $_POST['rollno'];

    // JOIN studreg and mark table
    $query = "
        SELECT studreg.*, mark.*
        FROM studreg
        JOIN mark ON studreg.rollno = mark.rollno
        WHERE studreg.rollno = '$roll'
    ";

    $queryresult = mysqli_query($con, $query);

    if ($row = mysqli_fetch_assoc($queryresult)) {

        echo "<h2 style='margin-top:20px;'>Progress Card</h2>";

        echo "
        <table border='1' cellpadding='10' cellspacing='0' 
               style='width: 400px; border-collapse: collapse; font-size: 16px;'>
               
            <tr style='background:#f0f0f0;'>
                <th colspan='2'>Student Details</th>
            </tr>
            <tr>
                <td><b>Roll No</b></td>
                <td>{$row['rollno']}</td>
            </tr>
            <tr>
                <td><b>Name</b></td>
                <td>{$row['name']}</td>
            </tr>

            <tr style='background:#f0f0f0;'>
                <th colspan='2'>Marks</th>
            </tr>
            <tr>
                <td><b>Science</b></td>
                <td>{$row['science']}</td>
            </tr>
            <tr>
                <td><b>English</b></td>
                <td>{$row['english']}</td>
            </tr>
            <tr>
                <td><b>Maths</b></td>
                <td>{$row['maths']}</td>
            </tr>

            <tr style='background:#d8ffd8;'>
                <td><b>Total</b></td>
                <td><b>" . ($row['science'] + $row['english'] + $row['maths']) . "</b></td>
            </tr>
        </table>
        ";

    } else {
        echo "No record found";
    }
}

mysqli_close($con);
?>
