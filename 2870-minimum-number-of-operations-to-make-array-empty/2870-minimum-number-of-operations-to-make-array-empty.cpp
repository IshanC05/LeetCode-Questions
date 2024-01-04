class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int>freq;
        
        for(int i : nums){
            ++freq[i];
        }
        
        int res = 0;
        
        for(auto it : freq){
            if(it.second == 1)  return -1;            
            
            res += ceil((double)(it.second) / 3);
        }
        
        return res;
    }
};