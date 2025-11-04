import math
q1=int(input("enter the coefficient of x^2"))
q2=int(input("enter the coefficient of x"))
q3=int(input("enter the constant"))
d=(q2*q2)-4*q1*q3
if(d>0):
    w=(math.sqrt(d))
    
print(w)
r1=(-q2+w)/2*q1
r2=(-q2-w)/2*q1
print("roots are %d%d",r1,r2)

