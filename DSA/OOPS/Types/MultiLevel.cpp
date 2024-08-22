// Multilevel inheritance 

#include<iostream>
using namespace std;

class Fruit{
    public: 
        string name;
        string getName(){
            return this->name;
        }
};

class Mango:public Fruit{
    public:
        float weight;
        float getWeight(){
            return this->weight;
        }
};

class totapuri: public Mango{
    public: 
        string color;
        string getColor(){
            return this->color;
        }
};

int main(){
    totapuri* t1=new totapuri;
    t1->name="Green Totapuri";
    t1->color="Green";
    t1->weight=1.4;
    cout<<"Name of mango :"<<t1->getName()<<endl;
    cout<<"Color of mango :"<<t1->getColor()<<endl;
    cout<<"Weight of mango :"<<t1->getWeight()<<endl;
    return 0;
}