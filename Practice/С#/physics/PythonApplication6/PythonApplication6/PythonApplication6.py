import turtle
import math

sat = turtle.Turtle()

def way_to_orbit(x,y, object, colors):
    object.dot(50, "Blue")
    object.color("black")
    object.fillcolor(colors)
    object.shape("circle")
    object.penup()
    object.setposition(x, y)
    object.pendown()

def info(x,y, object, colors):
    object.write("Home = ", True, align="left")
    object.color("black")
    object.fillcolor(colors)
    object.shape("circle")
    object.penup()
    object.setposition(10, 10)
    object.pendown()

def ellipse(object1):

    loop = True
    object1_xvel = 0
    object1_yvel = 1

    while loop:

        object1_xvel += math.cos(math.radians(object1.towards(0, 0))) * (00 / (object1.xcor() ** 2 + object1.ycor() ** 2))
        object1_yvel += math.sin(math.radians(object1.towards(0, 0))) * (1100 / (object1.xcor() ** 2 + object1.ycor() ** 2))
        object1.setposition(object1.xcor() + object1_xvel, object1.ycor() + object1_yvel)


way_to_orbit(200, 0, sat, "grey")


ellipse(sat)


turtle.done()
