import csv

data = [
    {"Name": "Alice", "Age": 25, "City": "New York"},
    {"Name": "Bob", "Age": 30, "City": "London"},
    {"Name": "Charlie", "Age": 28, "City": "Paris"}
]

fieldnames = ["Name", "Age", "City"]

with open("people_dict.csv", "w", newline="") as file:
    writer = csv.DictWriter(file, fieldnames=fieldnames)
    writer.writeheader()      # write the column names
    writer.writerows(data)    # write all rows

print("Dictionary data written to people_dict.csv successfully!")
with open("people_dict.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row)