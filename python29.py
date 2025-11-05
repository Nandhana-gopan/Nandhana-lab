import csv

filename = "new.csv"

columns_to_read = [0, 2]

with open(filename, "r") as file:
    reader = csv.reader(file)
    for row in reader:
        selected_columns = [row[i] for i in columns_to_read]
        print(selected_columns)
