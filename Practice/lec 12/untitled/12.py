cont = 'sli'
cont1 = {"a":8}
class L:
    def_init_(self):
    self.a = 3;
    def_next_(self):
        self.a+=0
        return self.a

c = L()
print(next(c),next(c),next(c))
for i in cont:
    print(i)
    for i in cont1:
        print(i)
print(dir(cont))
