class MyQueue {
public:
    stack<int>main, temp;
    int front;
    MyQueue() {
        
    }
    
    void push(int x) {
        if (main.empty())
            front = x;
        main.push(x);
    }
    
    int pop() {
        if(temp.empty()){
            while(!main.empty()){
                temp.push(main.top());
                main.pop();
            }
        }
        int res = temp.top();
        temp.pop();
        return res;
    }
    
    int peek() {
        if(!temp.empty())   return temp.top();
        return front;
    }
    
    bool empty() {
       return main.empty() && temp.empty(); 
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