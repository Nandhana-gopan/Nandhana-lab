import turtle
import random

# Set up the screen
screen = turtle.Screen()
screen.bgcolor("black")
screen.title("Turtle Graphics - Colorful Spiral")

# Create the turtle
t = turtle.Turtle()
t.speed(0)  # Fastest drawing speed
t.width(6)

# List of colors
colors = ["red", "orange", "yellow", "green", "blue", "purple"]

# Draw a spiral pattern
for i in range(150):
    t.color(random.choice(colors))
    t.forward(i * 2)
    t.left(61)

# Hide the turtle
t.hideturtle()

# Keep the window open until closed
turtle.done()
