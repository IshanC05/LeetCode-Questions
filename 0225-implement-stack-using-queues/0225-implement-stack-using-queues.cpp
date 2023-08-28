class MyStack {
public:
    queue<int>input, main;
    
    MyStack() {
        
        queue<int>q1, q2;
        
        main = q1, input = q2;
        
    }
    
    void push(int x) {
        
        input.push(x);
        
        while(!main.empty()){
            
            input.push(main.front());
            
            main.pop();
            
        }
        
        while(!input.empty()){
            
            main.push(input.front());
            
            input.pop();
            
        }
        
    }
    
    int pop() {
        
        int ans = -1;
        
        if(!empty()){
            
            ans = main.front();
            
            main.pop();
        }
        
        return ans;
    }
    
    int top() {
        
        int ans = -1;
        
        if(!empty()){
            
            ans = main.front();
        }
        
        return ans;
    }
    
    bool empty() {
        
        return main.size() == 0;
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */