import math
def equal(a, b, e=1E-10):
   if -e < a - b < e: return True
   else: return False
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

    def testPoint(x=0,y=0):
        p1 = Point(3, 4)
        print p1
        p2 = Point(3,0)
        print p2
        return math.hypot(dx, dy)

    print "distance = %s"%(testPoint()) 

class Vector:

    def __init__(self, point1, point2):
        self.point1 = tuple(point1)
        self.point2 = tuple(point2)
        self.direction = tuple(p1 - p2 for p1, p2 in (self.point1, self.point2))

    def __mul__(self, other):
        sum = 0
        for i in range(len(self.point1)):
            sum += self.direction[i] * other.direction[i]
        return sum

v1 = VectorExample((0, 0), (3, 4))
v2 = VectorExample((1, 0), (5, 8))

print(v1 * v2)

def gcd(m,n):
    while m % n != 0:
        oldm = m
        oldn = n
        m = oldn
        n = oldm % oldn
    return n
    
a = Vector(Point(1, 2))
b = Vector(Point(-2, 0), Point(-1, 2))
if a == b and b == a: print('Equality test passed')
else: print('Equality test failed')
na = Vector(Point(-1, -2))
ox = Vector(Point( 1,  0))
nox = Vector(Point(-1,  0))
oy = Vector(Point( 0,  1))
noy = Vector(Point( 0, -1))
if a == -na and na == -a and -ox == nox and -oy == noy: print('Invert test passed')
else: print('Invert test failed')
if ox + oy + oy == a and -ox == -a + oy + oy: print('Summation test passed')
else: print('Summation test failed')
if -ox + oy == oy - ox and -oy + ox == ox - oy: print('Subtraction test passed')
else: print('Subtraction test failed')
if (ox * 3 == ox + ox + ox and
   oy * 3 == oy + oy + oy and
   ox * (-3) == -ox - ox - ox and
   oy * (-3) == -oy - oy - oy): print('Multiplication by number test passed')
else: print('Multiplication by number test failed')
if (equal(ox.length(), 1) and
   equal(oy.length(), 1) and
   equal((ox * 3 + oy * 4).length(), 5)): print('Length test passed')
else: print('Length test failed')
if (equal(ox*ox, ox.length()**2) and
   equal(oy*oy, oy.length()**2) and
   equal((ox*3 + oy*4)*(ox*3 + oy*4), (ox*3 + oy*4).length()**2)): print('Multiplication by Vector test
passed')
else: print('Multiplication by Vector test failed')
