def fib(n):
    if n==0 or n==1:
        return 1
    else:
        return fib(n-1)+fib(n-2)
def generate_fib(n):
    for i in range(n):
        print(fib(i))    
#generate_fib(10)
n=int(input("enter n"))
d=generate_fib(n)
#1print(d)
