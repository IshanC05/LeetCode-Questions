class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int>freq;
        
        int maxF = 0, n = nums.size();
        
        for(int i : nums){
            ++freq[i];
            maxF = max(maxF, freq[i]);
        }
        
        vector<int>t(maxF + 5, INT_MAX);
        t[1] = -1;
        t[2] = t[3] = 1;
        
        for(int i = 4; i < t.size(); i++){
            if(i % 3 == 0)  t[i] = min(t[i], i / 3);
            if(i % 2 == 0)  t[i] = min(t[i], i / 2);
            int a = 1 + t[i - 2];
            int b = 1 + (t[i - 3] == -1 ? INT_MAX - 1: t[i - 3]);
            t[i] = min({t[i], a, b});
        }
        
        int res = 0;
        
        for(auto it : freq){
            if(it.second == 1)  return -1;            
            
            res += t[it.second];
        }
        
        return res;
    }
};