class MyQueue {
public:
    stack<int>main, temp;
    MyQueue() {
        
    }
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        int res = -1;
        if(main.empty())    return res;
        
        while(!main.empty()){
            temp.push(main.top());
            main.pop();
        }
        
        res = temp.top();
        temp.pop();
        
        while(!temp.empty()){
            main.push(temp.top());
            temp.pop();
        }
        
        return res;
    }
    
    int peek() {
        int res = -1;
        if(main.empty())    return res;
        
        while(!main.empty()){
            temp.push(main.top());
            main.pop();
        }
        
        res = temp.top();
        
        while(!temp.empty()){
            main.push(temp.top());
            temp.pop();
        }
        
        return res;
    }
    
    bool empty() {
       return main.empty(); 
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