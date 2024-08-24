#include<iostream>
using namespace std;

class A{
    private:
        int x;
        int y;
    public:
        // old style of writhing constructor 
        // A(int x,int y){
        //     this->x=x;
        //     this->y=y;
        // }
        //intialization list 
        A(int a,int b):x(a),y(b){
            cout<<"Values successfully intialized!"<<endl;
        }


        int getX() const{
            return this->x;
        }
        int getY() const{
            return this->y;
        }
        void setX(int x){
            this->x=x;
        }
        void setY(int y){
            this->y=y;
        }
};

void printXY(A const &a){
        cout<<"Value of x is "<<a.getX()<<endl;
        cout<<"Value of y is "<<a.getY()<<endl;
}

int main(){
    A *a=new A(10,20);
    printXY(*a);


    return 0;
}