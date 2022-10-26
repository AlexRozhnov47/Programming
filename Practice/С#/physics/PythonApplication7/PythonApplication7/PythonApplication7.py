import matplotlib.pyplot as plt
import numpy as np
from datetime import datetime

def f1(t,x,vx):
    return(vx)
def f2(t,x,vx):
    return(-GM*x/(x**2+y**2)**1.5)
def g1(t,x,vx):
    return(vy)
def g2(t,x,vx):
    return(-GM*y/(x**2+y**2)**1.5)
print("Введите множитель для радиуса от 0 до 10")
r1 = int(input())
r= 1.52e11*r1
print("Введите период вашей орбитализации обьекта (колличество дней)")
d = int(input())
tmax=d*24*3600
x=r
y=0.0
vx= 0
print("Введите значение для ускорения спутника (лучше в диапазоне от 10000 до 100000)")
vy= int(input())
t=0
print("Введите множитель для гравитационной силы Земли от 0 до 100")
gm = int(input())
GM= 1.334e+20*gm
xpos=[x]
ypos=[y]
print("Введите значение для промежуточных шагов выполнения программы")
h = int(input())
    #слой предикторов
while(t<tmax):
      k1=h*f1(t,x,vx)
      l1=h*f2(t,x,vx)
      m1=h*g1(t,x,vx)
      n1=h*g2(t,x,vx)
      k2=h*f1(t+h/2.0,x+k1/2.0,vx+l1/2.0)
      l2=h*f2(t+h/2.0,x+k1/2.0,vx+l1/2.0)
      m2=h*g1(t+h/2.0,x+m1/2.0,vx+n1/2.0)
      n2=h*g2(t+h/2.0,x+m1/2.0,vx+n1/2.0)
      k3=h*f1(t+h/2.0,x+k2/2.0,vx+l2/2.0)
      l3=h*f2(t+h/2.0,x+k2/2.0,vx+l2/2.0)
      m3=h*g1(t+h/2.0,x+m2/2.0,vx+n2/2.0)
      n3=h*g2(t+h/2.0,x+m2/2.0,vx+n2/2.0)
      k4=h*f1(t+h,x+k3,vx+l3)
      l4=h*f2(t+h,x+k3,vx+l3)
      m4=h*g1(t+h,x+m3,vx+n3)
      n4=h*g2(t+h,x+m3,vx+n3)
      x=x+(k1+k2*2.0+k3*2.0+k4)/6.0
      vx=vx+(l1+l2*2.0+l3*2.0+l4)/6.0
      y=y+(m1+m2*2.0+m3*2.0+m4)/6.0
      vy=vy+(n1+n2*2.0+n3*2.0+n4)/6.0
      t=t+h
      xpos.append(x)
      ypos.append(y)
plt.figure(1,figsize=[10,10])
plt.axis([-r,r,-r,r])
plt.scatter([0],[0],color='b')
plt.plot(xpos,ypos)
plt.show()