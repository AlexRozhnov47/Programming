import numpy as np
import matplotlib.pyplot as plt
from matplotlib import animation as am
np.random.seed(69420)
N=790 #Number of steps
# Have the particle at the origin in 2D (x,y) plane
# Each step will have a lenght of 1 unit. Lets call it meters
# Each step is one second
# And this simulation will run for 100 seconds
## Now how to make a particle randomly walk???
t=100 # time interval
dt=t/N # delta time from each step
dx = np.random.randint(-5,5,N,dtype=int)# This would be our detla x for each step
dy = np.random.randint(-5,5,N,dtype=int)
dx_0 = np.zeros(N, dtype=int)
dy_0 = np.zeros(N,dtype=int)
X = dx_0+dx
Y = dy_0+dy
print(X)
xdis = np.cumsum(X)  #Total distance travled after N steps
ydis = np.cumsum(Y)
plt.plot(dx_0,dy_0,'ko')
plt.plot(xdis,ydis,'b-')
plt.show()
