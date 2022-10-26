from vpython import sphere, vector, color, rotate
import math

# Константы
G = 6.667e-11  # гравитационная постоянная, м^3 кг^-1 с^-2
ME = float(input())  # масса Земли, кг
MM = float(input()) # масса Спутника, кг
RSE = float(input())# расстояние от Земли до Луны
a = int(input()) #Множитель для расстояния
r = int(input()) #Множитель радиуса спутника
R = int(input()) #Множитель радиуса планеты
# Гравитационная сила между Землей  и Спутником. 
F_SE = G*ME*MM/(RSE*RSE)
# Угловая скорость Спутника
we = math.sqrt(F_SE/(MM*RSE))
v = vector(0.5, 0, 0)
#Отображение модели в браузере в стартовой позиции
Sattelite = sphere(pos=vector(a, 0, 0), color=color.white, radius=r, make_trail=True)
Earth = sphere(pos=vector(0, 0, 0), color=color.blue, radius=R)

# Будем использовать полярные координаты
# Шаг
dt = 10
# углы поворота за один шаг:
theta_Sattelite = we*dt
while dt <= 86400*365:
    # Земля и Спутник поворачиваются вокруг оси z (0,0,1)
    Sattelite.pos = rotate(Sattelite.pos, angle=theta_Sattelite, axis=vector(0, 0, a))
    v = rotate(v, angle=theta_Sattelite, axis=vector(0, 0, 1))
    dt += 10
