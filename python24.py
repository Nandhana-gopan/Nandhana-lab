class BankAccount:
    def __init__(self,account_number,account_holder,balance=0):
        self.account_number=account_number
        self.account_holder=account_holder
        self.balance=balance
    def deposit(self,amount):
        if amount>0:
            self.balance+=amount
            print(f"₹{amount}deposited.New balance:₹{self.balance}")
        else:
            print(" deposit amount must be positive!")
    def withdraw(self,amount):
        if amount>0:
            if amount<=self.balance:
                self.balance-=amount
                print(f"₹{amount}withdrawn.New balance:₹{self.balance}")
            else:
                print("Insufficient balance!")
        else:
            print("withdrawal amount must be positive!")
    def check_balance(self):
        print(f"current balance:₹{self.balance}")
my_account = BankAccount("12345678","Nandhana gopan",10000)
my_account.check_balance()
my_account.deposit(800)
my_account.withdraw(2000)
my_account.withdraw(10000)



 
        
    