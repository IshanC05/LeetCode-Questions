class RandomizedCollection {
public:
    vector<int>list;
    unordered_map<int,unordered_set<int>>map1;
    
    RandomizedCollection() {
        vector<int>tempList;
        list = tempList;
        unordered_map<int,unordered_set<int>>mp;
        map1 = mp;
    }
    
    bool insert(int val) {
        bool check = false;
        if(map1.find(val) == map1.end()){
            unordered_set<int>s1;
            s1.insert(list.size());
            map1[val] = s1;
            list.push_back(val);
            check = true;
        }else{
            map1[val].insert(list.size());
            list.push_back(val);
        }
        return check;        
    }
    
    bool remove(int val) {
        bool check = false;
        auto it = map1.find(val);
        if(it != map1.end()){
            auto free_idx = *it->second.begin();
            it->second.erase(free_idx);
            list[free_idx] = list.back();
            map1[list.back()].insert(free_idx);
            map1[list.back()].erase(list.size() - 1);
            list.pop_back();
            if(map1[val].size() == 0)   map1.erase(val);
            check = true;
        }
        return check;
    }
    
    int getRandom() {
        return list[rand() % (list.size())];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */