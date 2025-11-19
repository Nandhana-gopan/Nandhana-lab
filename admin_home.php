<?php
session_start();
if(!isset($_SESSION['admin'])){
    header("Location:login.php");
    exit;
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Admin Home</title>

    <style>
        .container {
            display: flex;
            height: 100vh;
        }
        .left {
            width: 25%;
            border-right: 1px solid #000;
            padding: 10px;
        }
        .section {
            border-bottom: 1px solid #aaa;
            padding: 10px 0;
        }
        .right {
            width: 75%;
        }
        iframe {
            width: 100%;
            height: 100%;
            border: none;
        }
        a {
            text-decoration: none;
        }
    </style>
</head>

<body>

<div class="container">

    <!-- LEFT SIDE MENU -->
    <div class="left">
        <h3>admin home</h3>

        <div class="section">
            <a href="studentreg.php" target="contentFrame">student registration</a>
        </div>

        <div class="section">
            <a href="markentry.php" target="contentFrame">mark entry</a>
        </div>

        <div class="section">
            <a href="markupdate.php" target="contentFrame">mark update</a>
        </div>

        <div class="section">
            <a href="student_view.php" target="contentFrame">update student</a>
        </div>
        <div class="section">
            <a href="progresscard.php" target="contentFrame">progress card</a>
        </div>

    </div>

    <!-- RIGHT SIDE IFRAME -->
    <div class="right">
        <iframe name="contentFrame"></iframe>
    </div>

</div>

</body>
</html>
