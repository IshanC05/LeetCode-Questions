class RandomizedSet {
public:
    unordered_set<int>st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        int prevSz = st.size();
        st.insert(val);
        return !(prevSz == st.size());
    }
    
    bool remove(int val) {
        return st.erase(val);   
    }
    
    int getRandom() {
        int idx = (rand() % st.size());
        
        int res = -1;
        
        for(int i : st){
            res = i;
            --idx;
            if(idx == 0)    break;
        }
        
        return res;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */