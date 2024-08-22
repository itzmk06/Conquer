#include<iostream>
using namespace std;


//pubilc public 
class Animal{
    public: 
        int age;
        void sayHello(){
            cout<<"Hello from base class!"<<endl;
        }
};
class Dog:public Animal{
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