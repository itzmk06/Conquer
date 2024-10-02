class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            while(!st1.empty()){
                int data=st1.top();
                st2.push(data);
                st1.pop();
            }
        }
        int data=st2.top();
        st2.pop();
        return data;

    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                int data=st1.top();
                st2.push(data);
                st1.pop();
            }
        }
        int data=st2.top();
        return data;
    }
    
    bool empty() {
        return st2.empty()&&st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */