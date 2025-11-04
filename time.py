class Time:
    def __init__(self,hours=0,minutes=0,seconds=0):
        self.__hours=hours
        self.__minutes=minutes
        self.__seconds=seconds
    def display(self):
        print(f"{self.__hours:02d}:{self.__minutes:02d}:{self.__seconds:02d}")
    def __add__(self,other):
        hours = self.__hours + other.__hours
        minutes = self.__minutes + other.__minutes
        seconds = self.__seconds + other.__seconds
        return Time(hours,minutes,seconds)
t1=Time(2,30,45)
t2=Time(3,15,35)
t3=t1+t2
t1.display()
t2.display()
print("sum of times")
t3.display()
        
        
    