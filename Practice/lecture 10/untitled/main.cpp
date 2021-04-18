#include <iostream>

using namespace std;
int sum(int a,int b){
 return a+b;
}
int s = 0;
int* ptr_to_a = &s;
int *ptr;
int (*ptr_to_sum)(int, int) = sum;
typedef int (*psum)(int, int) ;
using psum = int (*) (int, int);
psum l = sum;

using predicat = bool (*)(int, int);
void sort(int m[], int size){
    for(int i = 0; i<size - 1; i++)
        for(int j = 0; i<i - 1; i++)
            if (m[j]>m[j+1]) std::swap(m[j], m[j+1]);
}
int main()
{ std::cout<< ptr_to_sum(1,1);
    auto p = [](){}()-> int;
    std::cout << p;
    return 0;
}
