#include<iostream>
using namespace std;

class Animal{
    int num1;
    int num2;
    char ch;

    private:
        int price;

    public:
    string name;
    int age;

    void eat(){
        cout<<"Eating!"<<endl;
    }
    void sleep(){
        cout<<"Sleeping!"<<endl;
    }
    int getPrice(){
        return price;
    }
    void setPrice(int p){
        price=p;
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
    a1.setPrice(101);
    int price=a1.getPrice();
    cout<<"Price of animal is "<<price<<endl;

    //by dynamic memory allocation 
    Animal* a2=new Animal;
    a2->name="Tiger";
    a2->age=20;
    cout<<a2->name<<endl;
    cout<<a2->age<<endl;

    delete a2;



    return 0;
}