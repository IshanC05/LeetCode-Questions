class MyStack {
public:
    queue<int>main;
    
    MyStack() {
        
        queue<int>q1;
        
        main = q1;
        
    }
    
    void push(int x) {
        
        main.push(x);
        
        for(int i = 0; i < main.size() - 1; i++){
            
            main.push(main.front());
            
            main.pop();
            
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