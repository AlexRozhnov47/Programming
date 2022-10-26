import numpy as np
import math
class Planet():
    def __init__(self,vx=0.0,vy=0.0,px=0.0,py=0.0,mass=0.0):
        self.vx=vx
        self.vy=vy
        self.px=px
        self.py=py
        self.mass = mass
        
def attract(p1,p2,grav=6.67428e-11):
    dx = p1.px - p2.px
    dy = p1.py - p2.py
    d = np.sqrt(dx**2 + dy**2)
    force = (grav * p1.mass * p2.mass)/d**2
    theta = math.atan2(dy,dx)
    fx = math.cos(theta)*force
    fy = math.sin(theta)*force
    return fx,fy

def loop(bodies,epochs=10,timestep=10):
    # compute forces
    forces = {}
    for i in range(0,len(bodies)):
        total_fx = 0
        total_fy = 0
        for j in range(0,len(bodies)):
            if i == j:
                continue
            fx,fy = attract(bodies[i],bodies[j])
            total_fx += fx
            total_fy += fy
        forces[i] = (total_fx,total_fy)
    #apply forces 
    sat_tups = []
    for e in range(epochs):
        for i in range(len(bodies)):
            if bodies[i] == satellite:
                sat_tups.append((bodies[i].px,bodies[i].py))            
            fx,fy = forces[i]
            bodies[i].vx += (fx/bodies[i].mass*timestep)
            bodies[i].vy += (fy/bodies[i].mass*timestep)
            bodies[i].px += bodies[i].vx*timestep
            bodies[i].py += bodies[i].vy*timestep  

    return sat_tups
        
 

earth = Planet(mass = 5.9742 * 10**24)
satellite = Planet(mass= 3000.0, px= 1414.0, py= 1414.0, vx=2300.0,vy=2300.0)
tups = loop(bodies=[earth,satellite])


