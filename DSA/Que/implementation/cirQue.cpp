#include<iostream>
using namespace std;

class CirQue{
    public:
        int rear;
        int front;
        int size;
        int *arr;
        
        CirQue(int size){
            this->size=size;
            arr=new int[size];
            front=rear=-1;
        }

        void push(int data){
            // check whether stack is full 
            if((((rear+1)%size)==front)){
                cout<<"Stack is full"<<endl;
            }
            // this is first insertion 
            else if(front==-1&&rear==-1){
                front=rear=0;
                                arr[rear]=data;
            }
            // circular insertion 
            else if((rear==size-1)&&(front!=0)){
                rear=0;
                arr[rear]=data;
            }
            // normal flow
            else{
                rear++;
                arr[rear]=data;
            }

        }

        void pop(){
            // check whether que is empty or not
            if(front==-1&&rear==-1){
                cout<<"Que is empty!"<<endl;
            }
            // handle for only one element in queue
            else if(front==rear){
                arr[front]=-1;
                front=rear=-1;
            }
            // handle for circular nature 
            else if((front==size-1)){
                arr[front]=-1;
                front=0;
            }
            // normal flow 
            else{
                arr[front]=-1;
                front++;
            }
        }
        void display(){
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }



};

int main(){

    CirQue c(5);
    c.display();
    c.push(1);
    c.push(2);
    c.push(3);
    c.push(4);
    c.push(5);
    // c.push(6);
    c.display();
    c.pop();
    c.pop();
    c.pop();
    // c.pop();
    // c.pop();
    // c.pop();
    c.display();
    c.push(10);
    c.push(20);
    c.push(30);
    // c.push(40);
    c.display();
    c.pop();
    c.pop();
    c.pop();
    c.pop();
    c.pop();
    c.pop();
    c.display();
    


    return 0;
}


//* using modulus 

#include<iostream>
using namespace std;

class CirQue{
    public:
        int rear;
        int front;
        int size;
        int *arr;
        
        CirQue(int size){
            this->size = size;
            arr = new int[size];
            front = rear = -1;
        }

        void push(int data) {
            // Check if the queue is full
            if (((rear + 1) % size) == front) {
                cout << "Queue is full" << endl;
                return;
            }
            // First insertion
            else if (front == -1 && rear == -1) {
                front = rear = 0;
                arr[rear] = data;
            }
            // Circular insertion when rear reaches the end and there's space at the beginning
            else if (rear == size - 1 && front != 0) {
                rear = 0;
                arr[rear] = data;
            }
            // Normal insertion
            else {
                rear = (rear + 1) % size;
                arr[rear] = data;
            }
        }

        void pop() {
            // Check if the queue is empty
            if (front == -1) {
                cout << "Queue is empty!" << endl;
                return;
            }
            // Handle the case when only one element is left
            else if (front == rear) {
                arr[front] = -1;
                front = rear = -1;
            }
            // Handle the circular nature when front reaches the end
            else if (front == size - 1) {
                arr[front] = -1;
                front = 0;
            }
            // Normal flow for dequeuing
            else {
                arr[front] = -1;
                front = (front + 1) % size;
            }
        }

        void display() {
            if (front == -1) {
                cout << "Queue is empty!" << endl;
                return;
            }
            cout << "Queue elements: ";
            if (rear >= front) {
                // Print elements from front to rear
                for (int i = front; i <= rear; i++)
                    cout << arr[i] << " ";
            } else {
                // Circular queue case
                for (int i = front; i < size; i++)
                    cout << arr[i] << " ";
                for (int i = 0; i <= rear; i++)
                    cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    CirQue c(5);
    c.display();

    c.push(1);
    c.push(2);
    c.push(3);
    c.push(4);
    c.push(5);
    c.display();

    c.pop();
    c.pop();
    c.pop();
    c.display();

    c.push(10);
    c.push(20);
    c.push(30);
    c.display();

    c.pop();
    c.pop();
    c.pop();
    c.pop();
    c.pop();
    c.display();

    return 0;
}
