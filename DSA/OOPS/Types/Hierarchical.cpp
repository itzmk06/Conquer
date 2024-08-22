//Hierarchical inheritance 
#include<iostream>
using namespace std;

class Car{
    public:
        string name;
        string model;
        void speedUp(){
            cout<<"Speeding up!!!!"<<endl;
        }
};
class Audi:public Car{
    public: 
        Audi(){
            cout<<"Hello from Audi"<<endl;
        }
};
class Benz:public Car{
    public:
        Benz(){
            cout<<"Hello from benz"<<endl;
        }
} ;

int main(){
    Audi a;
    a.name="Audi";
    a.model="X90";
    a.speedUp();
    Benz b;
    b.name="Benz";
    b.model="D44";
    b.speedUp();

    return 0;
}