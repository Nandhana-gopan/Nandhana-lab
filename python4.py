a=int(input("enter the first number"))
b=int(input("enter the second number"))
i=int(input("enter the choice:\n1.Addition\n2.subtraction\n3.multiplication\n4.division"))
if(i==1):
    sum=a+b
    print("sum is",sum)
elif(i==2):
    sub=a-b
    print("result is",sub)
elif(i==3):
    mul=a*b
    print("result is",mul)
elif(i==4):
    div=a/b
    print("result is",div)   
else:
    print("invalid choice")
    
    
    
    
    
    