#include<iostream>
using namespace std;

class MethodOver{
    public:
        virtual void sayHello(){
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
    // MethodOver* m=new MethodOver();
    // m->sayHello();

    MethodOver* m=new Wow();
    m->sayHello();

    // Wow* w=new Wow();
    // w->sayHello();

    // Wow* w=(Wow*)new MethodOver();
    // w->sayHello();


    return 0;
}