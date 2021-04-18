#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double sqr(double a);
bool equal(double a, double b, double e = 1E-10);

class Point{
private:
    int *x,*y;
public:
    Point();
    ~Point();
    Point(const Point &obj);
    int get_x(){ return *x;}
    int get_y(){ return *y;}
};
Point::Point(const Point &obj){
     x = new int;
     y = new int;
     *x = *obj.x;
     *y = *obj.y;
}
Point::Point(){
    x = new int;
    y = new int;
    *x = 1+rand()%10;
    *y = 1+rand()%10;
}
Point::~Point(){
    delete x;
    delete y;
}
void show(Point obj){
    cout<<"point("<<obj.get_x()<<";"<<obj.get_y()<<")";
}
double range(Point obj){
    return sqrt(obj.get_x()*obj.get_x()+obj.get_y()*obj.get_y());
}

using namespace std;
template <typename T> class Vector
{
    T* arr;
    int a;
    int b;

public:

    Vector()
    {
        arr = new T[1];
        a = 1;
        b = 0;
    }


    void push(T data)
    {


        if (b == a) {
            T* temp = new T[2 * a];
            for (int i = 0; i < a; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            a *= 2;
            arr = temp;
        }

        arr[b] = data;
        b++;
    }

    void push(int data, int index)
    {
        if (index == a)
            push(data);
        else
            arr[index] = data;
    }

    T get(int index)
    {

        if (index < b)
            return arr[index];
    }

    void pop() { b--; }
    int size() { return b; }
    int getcapacity() { return a; }

    void print()
    {
        for (int i = 0; i < b; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Vector a(Point(1, 2)), b(Point(-2, 0), Point(-1, 2));
    if (a == b && b == a) cout << "Equality test passed\n";
    else cout << "Equality test failed\n";

    Vector na(Point(-1, -2)), ox(Point(1, 0)), nox(Point(-1, 0)), oy(Point(0, 1)), noy(Point(0, -1));
    if (a == -na && na == -a && -ox == nox && -oy == noy) cout << "Invert test passed\n";
    else cout << "Invert test failed\n";

    if (ox + oy + oy == a && -ox == -a + oy + oy) cout << "Summation test passed\n";
    else cout << "Summation test failed\n";

    if (-ox + oy == oy - ox && -oy + ox == ox - oy) cout << "Subtraction test passed\n";
    else cout << "Subtraction test failed\n";

    if (ox * 3 == ox + ox + ox &&
        oy * 3 == oy + oy + oy &&
        ox * (-3) == -ox - ox - ox &&
        oy * (-3) == -oy - oy - oy) cout << "Multiplication by number test passed\n";
    else cout << "Multiplication by number test failed\n";

    if (equal(ox.length(), 1) &&
        equal(oy.length(), 1) &&
        equal((ox * 3 + oy * 4).length(), 5)) cout << "Length test passed\n";
    else cout << "Length test failed\n";

    if (equal(ox*ox, sqr(ox.length())) &&
        equal(oy*oy, sqr(oy.length())) &&
        equal((ox*3 + oy*4)*(ox*3 + oy*4), sqr((ox*3 + oy*4).length()))) cout << "Multiplication by Vector test passed\n";
    else cout << "Multiplication by Vector test failed\n";
}

bool equal(double a, double b, double e) {
    if (-e < a - b && a - b < e) return true;
    else return false;
}

double sqr(double a) {
    return a * a;
}
