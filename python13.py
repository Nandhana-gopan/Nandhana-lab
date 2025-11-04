str1=input("enter the string1")
str2=input("enter the string2")
print("first character of first string %d",str1[0])
print("first character of second string %d",str2[0])
swapped1= str2[0] + str1[1:]
swapped2= str1[0] + str2[1:]
print(swapped1)
print(swapped2)
print(swapped1+swapped2)
