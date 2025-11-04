def gcd(a, b):
    a, b = abs(a), abs(b)
    gcd_val = 1
    for i in range(min(a, b), 0, -1):
        if a % i == 0 and b % i == 0:
            gcd_val = i
            break
    return gcd_val

a = int(input("Enter the first number: "))
b = int(input("Enter the second number: "))
result = gcd(a, b)
print("GCD is:", result)
