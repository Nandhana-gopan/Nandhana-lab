lst=[]
n=int(input("enter the number of elements"))
for i in range(n):
    num=int(input("enter the number"))
    lst.append(num)
for num in lst:
  if(num>0):
    print(num)