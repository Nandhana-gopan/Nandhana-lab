lst = list(map(int, input("Enter numbers separated by space: ").split()))
odd = [num for num in lst if num % 2 != 0]
print(odd)
