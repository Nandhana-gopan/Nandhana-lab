<?php
$con = mysqli_connect("localhost", "root", "", "student");

if (!$con) {
    die("Database connection failed");
}

$result = mysqli_query($con, "SELECT * FROM studreg");
?>

<h2>Student Records</h2>

<table border="1" cellpadding="10">
    <tr>
        <th>Roll No</th>
        <th>Name</th>
        <th>Address</th>
        <th>Phone</th>
        <th>Action</th>
    </tr>

<?php
while ($row = mysqli_fetch_assoc($result)) {
    echo "<tr>";
    echo "<td>" . $row['rollno'] . "</td>";
    echo "<td>" . $row['name'] . "</td>";
    echo "<td>" . $row['address'] . "</td>";
    echo "<td>" . $row['phone'] . "</td>";

    echo "<td>
            <form action='student_update.php' method='post'>
                <input type='hidden' name='rollno' value='" . $row['rollno'] . "'>
                <input type='submit' value='Update'>
            </form>
          </td>";

    echo "</tr>";
}
?>

</table>

<?php mysqli_close($con); ?>
