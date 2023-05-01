class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>s;
        for(int x : nums){
            s.insert(x);
        }
        int i = 1;
        for(auto it = s.begin(); it != s.end(); it++){
            while(it != s.end() and *it != i){
                it++;
            }
            if(it == s.end()){
                return i;
            }
            if(*it != i){
                break;
            }
            ++i;
        }
        return i;
    }
};