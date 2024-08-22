#include<iostream>
using namespace std;

class MethodOver{
    public:
        void sayHello(){
            cout<<"Hello, World!"<<endl;
        }
};
class Wow:public MethodOver{
    public:
    void sayHello(){
        cout<<"Hello, Manoj!"<<endl;
    }
};

int main(){
    MethodOver m;
    m.sayHello();
    Wow w;
    w.sayHello();

    return 0;
}