#include<iostream>
using namespace std;

class A{
    public:
        static int x;
        static int y;
        void printXY(){
            cout<<"Value of x is "<<x<<"value of y is "<<y<<endl;
        }
};

int A::x;
int A::y;

int main(){
    A a;
    A b;
    a.x=10;
    a.y=20;
    a.printXY();
    cout<<endl;
    b.x=30;
    b.y=40;
    b.printXY();
    a.printXY();
    cout<<endl;

    return 0;
}