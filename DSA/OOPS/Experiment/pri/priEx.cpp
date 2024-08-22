#include<iostream>
using namespace std;

//private  pvivate
class Animal{
    private: 
        int age;
        void sayHello(){
            cout<<"Hello from base class!"<<endl;
        }
};
class Dog:private  Animal{
    public:
        Dog(){
            cout<<age<<endl;
            sayHello();
    }
};


int main(){
    Dog* d1=new Dog;
    return 0;
}