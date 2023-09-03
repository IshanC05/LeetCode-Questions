class RandomizedSet {
public:
    
    vector<int>list;
    unordered_map<int,int>map1;
    
    RandomizedSet() {
        vector<int>tempList;
        list = tempList;
        unordered_map<int,int>mp;
        map1 = mp;
    }
    
    bool insert(int val) {
        bool check = false;
        if(map1.find(val) == map1.end()){
            map1[val] = list.size();
            check = true;
            list.push_back(val);
        }
        return check;        
    }
    
    bool remove(int val) {
        bool check = false;
        if(map1.find(val) != map1.end()){
            check = true;
            int  lastIdx = list.size() - 1, lastElem = list[lastIdx];
            int remIdx = map1[val];
            map1[lastElem] = remIdx;
            map1.erase(val);
            swap(list[lastIdx], list[remIdx]);
            list.resize(lastIdx);
        }
        return check;
    }
    
    int getRandom() {
        return list[rand() % (list.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */