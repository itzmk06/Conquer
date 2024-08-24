#include<iostream>
using namespace std;

class B1{
    private:    
        B1(int w){
            this->w=w;
        }
    public:
        int w;
        void setWidth(int w){
            this->w=w;
        }
        int getWidth(){
            return this->w;
        }
        friend class B2;
};

class B2{
    public:
        B1 getWidth1(int w){
             B1 b(w);
             return b;
        }
};


int main(){
    B2 b;
    B1 b1=b.getWidth1(100);
    cout<<b1.getWidth()<<endl;
    return 0;
}