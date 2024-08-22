//Multiple inheritance 

#include<iostream>
using namespace std;

class A{
    public:
        string name;
        int age;
        A(){
            name="Manoj";
            age=20;
        }
};

class B{
    public:
        string name;
        int age;
        B(){
            name="Ketaki";
            age=22;
        }
};
class C:public A,public B{

};

int main(){

    C c1;
    // this creates ambiguity because compiler don't know which to access 
    // cout<<c1.name<<endl;
    // cout<<c1.age<<endl;

    cout<<c1.A::name<<endl;
    cout<<c1.A::age<<endl;

    
    cout<<c1.B::name<<endl;
    cout<<c1.B::age<<endl;

    // :: -> this is called as scope resolution operator 
    return 0;
}