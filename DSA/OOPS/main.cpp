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

    Animal(){
        this->price=0;
        this->name="";
        this->age=0;
        cout<<"Default constructor called!"<<endl;
    }
    Animal(int age){
        this->age=age;
        cout<<"Parameterized constructor 1 is called!"<<endl;
    }
    Animal(string name,int age){
        this->age=age;
        this->name=name;
        cout<<"Parameterized constructor 2 is called!"<<endl;
    }
    Animal(Animal &obj){
        cout<<"I am inside copy constructor!"<<endl;
        this->name=obj.name;
        this->age=obj.age;
    }

    //destructor 
    ~Animal(){
        cout<<"Destructor called!"<<endl;
    }


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

    // //static allocation of objects 
    // Animal a1;
    // // to assign values in static way 
    // a1.name="Lion";
    // a1.age=20;

    // cout<<"Name of animal is "<<a1.name<<endl;
    // cout<<"Age of animal is "<<a1.age<<endl;
    // a1.eat();
    // a1.sleep();
    // a1.setPrice(101);
    // int price=a1.getPrice();
    // cout<<"Price of animal is "<<price<<endl;

    // //by dynamic memory allocation 
    // Animal* a2=new Animal;
    // a2->name="Tiger";
    // a2->age=20;
    // cout<<a2->name<<endl;
    // cout<<a2->age<<endl;
    
    // Animal* a3=new Animal(10);
    // Animal a4("Manoj",20);
    // Animal a5(a4);

    // delete a2;

    Animal a;
    Animal* b=new Animal;
    delete b;



    return 0;
}