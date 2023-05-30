class MyHashSet {
public:
    vector<int>container;
    MyHashSet() {
        vector<int>temp;
        container = temp;
    }
    
    void add(int key) {
        if(contains(key)){
            return;
        }
        container.push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)){
            return;
        }
        for(auto it = container.begin(); it != container.end(); it++){
            if(*it == key){
                container.erase(it);
                break;
            }
        }
        return;
    }
    
    bool contains(int key) {
        for(int i : container){
            if(i == key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */