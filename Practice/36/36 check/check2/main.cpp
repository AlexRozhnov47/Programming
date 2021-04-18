#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
const auto PI = 3.141592653589793;
class Point{
private:
    int *x,*y;
public:
    point();
    ~point();
    point(const point &obj);
    int get_x(){ return *x;}
    int get_y(){ return *y;}
};
point::point(const point &obj){
     x = new int;
     y = new int;
     *x = *obj.x;
     *y = *obj.y;
}
point::point(){
    x = new int;
    y = new int;
    *x = 1+rand()%10;
    *y = 1+rand()%10;
}
point::~point(){
    delete x;
    delete y;
}
void show(point obj){
    cout<<"point("<<obj.get_x()<<";"<<obj.get_y()<<")";
}
double range(point obj){
    return sqrt(obj.get_x()*obj.get_x()+obj.get_y()*obj.get_y());
}
void main(){
    point a, b;
    show(a);
    cout<<endl;
    show(b);
    cout<<endl;
    cout<<"Range ="<<range(a)<<endl;
    cout<<"Range ="<<range(b)<<endl;
}
int main() {
 std::vector<Point> original;
 std::ifstream fin("data.txt");
 if (!fin.is_open()) {
 std::cout << "Can't open file" << std::endl;
 return 1;
 } else {
 while (!fin.eof()) {
 Point p;
 fin >> p;
 fin.ignore(2); // Точки разделены двумя символами ", "
 original.push_back(p);
 }
 fin.close();
 }
 std::vector<Point> simulacrum(original);
 for (auto& p : simulacrum) {
 std::cout << p;
 p.set_x(p.get_x() + 10);
 p.set_phi(p.get_phi() + 180*PI/180);
 p.set_y(-p.get_y());
 p.set_x(-p.get_x() - 10);
 std::cout << p << std::endl;
 }
 if (std::equal(original.begin(), original.end(), simulacrum.begin()))
 std::cout << "\nIt works!\n";
 else
 std::cout << "\nIt not works!\n";
}
