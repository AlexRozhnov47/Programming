import math
import copy
class Point(object):

    COUNT = 0

    def __init__(self, x, y):
        self.X = x
        self.Y = y

    def move(self, dx, dy):
        self.X = self.X + dx
        self.Y = self.Y + dy

    def __str__(self):
        return "Point(%s,%s)"%(self.X, self.Y) 


    def getX(self):
        return self.X

    def getY(self):
        return self.Y

    def distance(self, other):
        dx = self.X - other.X
        dy = self.Y - other.Y
        return math.sqrt(dx**2 + dy**2)
        
with open('data.txt') as fin:
   original = [Point(p) for p in fin.readline().split(', ')]
simulacrum = copy.deepcopy(original)
for p in simulacrum:
   print(p, end=
'')
   p.set_x(p.get_x() + 10)
   p.set_phi(p.get_phi() + 180*math.pi/180)
   p.set_y(-p.get_y())
   p.set_x(-p.get_x() - 10)
   print(p)
print('\nIt works!\n' if simulacrum == original else '\nIt not works!\n')
