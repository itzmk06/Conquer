#include<iostream>
using namespace std;

class Animal{
    private:
        string name;
        int age;

    public:
        void sayHell(){
            cout<<"Hello from animal!"<<endl;
        }
        void setName(string name){
            this->name=name;
        }
        void setAge(int age){
            this->age=age;
        }
        string getName(){
            return this->name;
        }
        int getAge(){
            return this->age;
        }
};

int main(){
    Animal* a1=new Animal;
    a1->setName("Manoj");
    a1->setAge(20);
    cout<<"Age of a1 is "<<a1->getAge()<<endl;
    cout<<"Name of a1 is "<<a1->getName()<<endl;
    return 0;
}