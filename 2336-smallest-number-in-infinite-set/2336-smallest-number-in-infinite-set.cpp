class SmallestInfiniteSet {
public:
    vector<bool>check;
    int i;
    
    SmallestInfiniteSet() {
        
        vector<bool>temp(1001, true);
        
        check = temp;
        
        i = 1;
    }
    
    int popSmallest() {
        
        check[i] = false;
        
        int ans = i;
        
        while(i < 1001 && check[i] == false){
         
            ++i;
            
        }
        
        return ans;
        
    }
    
    void addBack(int num) {
        
        if(check[num] == false){
            
            check[num] = true;
            
            if(num < i){
                
                i = num;
            }
            
        }
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */