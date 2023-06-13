class DataStream {
public:
    int val, count, k;
    DataStream(int value, int k) {
        this->val = value;
        this->k = k;
        count = 0;
    }
    
    bool consec(int num) {
        if(num == val){
            ++count;
        }else{
            count = 0;
        }
        return count >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */