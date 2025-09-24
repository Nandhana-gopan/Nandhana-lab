
lst = list(map(int, input("Enter a list of integers separated by spaces: ").split()))
for num in lst:
    if num > 100:
        print("over")
    else:
        print(num)
