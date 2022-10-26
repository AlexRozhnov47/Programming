import turtle
import math

def move_to_orbit(x,y, item, color):
    item.dot(50, "yellow")
    item.color("white")
    item.fillcolor(color)
    item.shape("circle")
    item.penup()
    item.setposition(x, y)
    item.pendown()


def move_on_orbits( object2, object3):


    object2_angle = 0
    object3_angle = 0

    while True:

        

        object2_angle += .1
        rad = math.radians(object2_angle)
        x = object2.xcor()
        y = object2.ycor()
        center_x = 0 # sun
        center_y = 0 # sun
        distance = ((x-center_x)**2 + (y-center_y)**2)**.5 # calculation are precise 
        #distance = 175 # distance to sun
        x = center_x + math.cos(rad) * distance 
        y = center_y + math.sin(rad) * distance
        object2.setposition(x, y)

        object3_angle += 2
        rad = math.radians(object3_angle)
        x = object3.xcor()
        y = object3.ycor()
        center_x = object2.xcor() # earth
        center_y = object2.ycor() # earth
        #distance = ((x-center_x)**2 + (y-center_y)**2)**.5 calculation are NOT precise
        distance = 30 # distance to earth
        x = center_x + math.cos(rad) * distance 
        y = center_y + math.sin(rad) * distance
        object3.setposition(x, y)



earth = turtle.Turtle()
spacecraft = turtle.Turtle()


move_to_orbit(175, 0, earth, "blue")
move_to_orbit(205, 0, spacecraft, "green")

move_on_orbits(earth, spacecraft)


turtle.done()
