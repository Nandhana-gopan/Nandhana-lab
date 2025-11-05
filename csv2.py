import csv

data = [
    ["Name", "Age", "City"],
    ["Alice", 25, "New York"],
    ["Bob", 30, "London"],
    ["Charlie", 28, "Paris"]
]

with open("new.csv", "w", newline="") as file:
    writer = csv.writer(file)
    writer.writerows(data)

print("CSV file created successfully!")

specific_lines = [2, 4]

with open("new.csv", "r") as file:
    reader = csv.reader(file)
    line_num = 1  
    for row in reader:
        if line_num in specific_lines:
            print(row)
        line_num += 1