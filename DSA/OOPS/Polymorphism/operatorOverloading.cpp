#include<iostream>
using namespace std;

class Ex{
    public:
        int val;
        int operator+(Ex& ob){
            return (this->val-ob.val);
        }
};

int main(){
    Ex e1;
    Ex e2;
    e1.val=10;
    e2.val=20;
    cout<<e1+e2<<endl;
    return 0;
}