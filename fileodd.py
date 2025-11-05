input_file = "source.txt"
output_file = "dest.txt"

with open(input_file, "r") as infile, open(output_file, "w") as outfile:
    line_number = 1
    for line in infile:
        if line_number % 2 == 1:  
            outfile.write(line)
        line_number += 1

print("Odd-numbered lines copied to", output_file)
