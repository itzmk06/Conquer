#include<iostream>
using namespace std;

class Animal{
    int num1;
    int num2;
    char ch;

    public:
    string name;
    int age;

    void eat(){
        cout<<"Eating!"<<endl;
    }
    void sleep(){
        cout<<"Sleeping!"<<endl;
    }
};


int main(){
    cout<<"The size of empty class is "<<sizeof(Animal)<<endl;
    //1 

    //static allocation of objects 
    Animal a1;
    // to assign values in static way 
    a1.name="Lion";
    a1.age=20;

    cout<<"Name of animal is "<<a1.name<<endl;
    cout<<"Age of animal is "<<a1.age<<endl;
    a1.eat();
    a1.sleep();

    return 0;
}