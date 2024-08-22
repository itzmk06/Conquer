// single level inheritance 

#include<iostream>
using namespace std;

class Car{
        public:
            int year;
            string model;
            string name;

        public: 
            string getName(){
                return this->name;
            }
            string getModel(){
                return this->model;
            }
};

class Scorpio:public Car{
    public: 
        void getData(){
            cout<<this->name<<endl;
            cout<<this->model<<endl;
        }
};

int main(){
    Scorpio* s1=new Scorpio;
    s1->name="Scorpio300";
    s1->model="900";
    s1->getData();

    return 0;
}