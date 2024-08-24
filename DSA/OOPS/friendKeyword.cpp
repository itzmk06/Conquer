#include<iostream>
using namespace std;

class Hello{
    private:
        int x;
    public:
        void setX(int x){
            this->x=x;
        }
        int getX(){
            return this->x;
        }
        friend class Hi;
        friend void showX(Hello h);
};

class Hi{
    public:
        void print(Hello h){
            cout<<"Value is "<<h.getX()<<endl;
        }
        void print1(Hello h){
            cout<<"Accessing directly "<<h.x<<endl;
        }
};

void showX(Hello h){
    cout<<h.x<<endl;
}

int main(){
    Hello h;
    h.setX(100);
    Hi i;
    i.print(h);
    i.print1(h);
    showX(h);

    return 0;
}