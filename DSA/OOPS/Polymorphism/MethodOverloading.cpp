//Method overloading 
// method parameters can change not the type of method 

#include<iostream>
using namespace std;

class Test{
    public:
        int sum(int a,int b){
            return (a+b);
        }
        int sum(int a,int b,int c){
            return (a+b+c);
        }
        int sum(int a,float b){
            return (a+b);
        }
        int sum(int a,double b){
            return (a+b);
        }
};

int main(){
    Test t;
    cout<<"The sum is "<<t.sum(10,20)<<endl;
    cout<<"The sum is "<<t.sum(10,20,30)<<endl;
    cout<<"The sum is "<<t.sum(10,20.33)<<endl;
    cout<<"The sum is "<<t.sum(10,20.33f)<<endl;
    return 0;
}