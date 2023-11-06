class SeatManager {
public:
    int i;
    set<int>available;
    SeatManager(int n) {
        i = 1;
    }
    
    int reserve() {
        int res;
        if(available.empty()){
            res = i;
            ++i;
        }else{
            auto it = available.begin();
            int smallest = *it;
            if(smallest < i){
                available.erase(smallest);
                res = smallest;
                return smallest;
            }else{
                res = i;
                ++i;
            }
        }
        
        return res;
    }
    
    void unreserve(int seatNumber) {
        available.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */