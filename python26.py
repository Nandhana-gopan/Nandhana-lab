# Base class
class Publisher:
    def __init__(self, name):
        self.name = name
        print(f"Publisher constructor called for: {self.name}")

    def display(self):
        print(f"Publisher Name: {self.name}")


# Derived class
class Book(Publisher):
    def __init__(self, name, title, author):
        # Call the base class constructor
        super().__init__(name)
        self.title = title
        self.author = author
        print(f"Book constructor called for: {self.title}")

    # Method overriding: overriding the base class display() method
    def display(self):
        # Call the parent method (optional)
        super().display()
        print(f"Book Title: {self.title}")
        print(f"Author: {self.author}")


# Create an object of Book
b1 = Book("Penguin Random House", "The Alchemist", "Paulo Coelho")

# Call the overridden display() method
b1.display()
