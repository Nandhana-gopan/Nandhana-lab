from datetime import datetime
current=datetime.now().year
final_year=int(input("enter the final year"))
for i in range(current,final_year+1):
    if(i % 4== 0 and i%100!=0) or (i%400==0):
        print(i)