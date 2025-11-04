<?php
$name = $_GET["name"];
$class = $_GET["class"];
$mark1 = $_GET["mark1"];
$mark2 = $_GET["mark2"];
$mark3 = $_GET["mark3"];
$total = $mark1 + $mark2 + $mark3;
//$average = $total / 3;
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Progress Report</title>
    <style>
        body {
            font-family: 'Poppins', sans-serif;
            background: linear-gradient(135deg, #dbeafe, #eff6ff);
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
        }

        .card {
            background:white;
            border-radius: 15px;
            box-shadow: 0 6px 20px rgba(0,0,0,0.1);
            padding: 30px 40px;
            width: 450px;
            text-align: center;
            border-top: 5px solid #bdeb25ff;
        }

        .card h2 {
            color:black;
            margin-bottom: 20px;
        }

        .info {
            text-align: left;
            font-size: 16px;
            line-height: 1.8;
            margin-bottom: 15px;
        }

        .marks-table {
            width: 100%;
            border-collapse: collapse;
            margin: 10px 0;
        }

        .marks-table th, .marks-table td {
            border: 1px solid #cbd5e1;
            padding: 8px;
        }

        .marks-table th {
            background-color: #eff6ff;
            color: #1e3a8a;
        }

        .summary {
            margin-top: 15px;
            font-weight: bold;
            color: #1d4ed8;
        }

        
    </style>
</head>
<body>
    <div class="card">
        <h2>Progress Report</h2>

        <div class="info">
            <strong>Name:</strong> <?= htmlspecialchars($name) ?><br>
            <strong>Class:</strong> <?= htmlspecialchars($class) ?>
        </div>

        <table class="marks-table">
            <tr>
                <th>Subject</th>
                <th>Marks</th>
            </tr>
            <tr>
                <td>English</td>
                <td><?= htmlspecialchars($mark1) ?></td>
            </tr>
            <tr>
                <td>Maths</td>
                <td><?= htmlspecialchars($mark2) ?></td>
            </tr>
            <tr>
                <td>Computer</td>
                <td><?= htmlspecialchars($mark3) ?></td>
            </tr>
        </table>

        <div class="summary">
            Total Marks: <?= $total ?><br>
            
        </div>

        
    </div>
</body>
</html>
