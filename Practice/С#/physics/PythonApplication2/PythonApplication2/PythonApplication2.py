import numpy as np 

T = 24. * 3600 # period of 1 day 
G = 6.67e-11 # SI units 
earth_mass = 5.97e24 # SI units 
 
# calculate some physical quantities 
radius = (G * earth_mass * T**2. / ( 3.14 ** 2.)) ** (1./3.) 
speed = 2.0 * 3.14 * radius / T 
 
# define parameters and initialize values 
num_steps = 100 # feel free to change this 
dt = T/num_steps # step size 
x = np.zeros([num_steps + 1, 2]) # y0 position left at zero 
x[0, 0] = radius #x0 at radius 
v = np.zeros([num_steps + 1, 2]) 
v[0, 0] = radius/2 # velocity is perpendicular to the radius 
 
# EULER method 
for step in range(num_steps): 
 x[step + 1] = x[step] + dt * v[step] 
 v[step + 1] = v[step] - dt * G * earth_mass / np.linalg.norm(-x[step])**3 * x[step] 
 
# copy values for comparison later 
x_euler = np.copy(x) 
v_euler = np.copy(v) 
 
# IMPROVED EULER method 
for step in range(num_steps): 
 x1 = x[step] + dt * v[step] 
 v1 = v[step] - dt * G * earth_mass / np.linalg.norm(-x[step])**3 * x[step] 
 x[step + 1] = x[step] + dt * 0.5 * (v[step] + v1) 
 #v[step + 1] = v[step] - dt * G * earth_mass ( 1./ np.linalg.norm(-x[step])**3 * x[step] + 1./ np.linalg.norm(-x1)**3 * x1)  

