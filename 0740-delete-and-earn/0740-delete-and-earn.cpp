class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int freq[10001] = {0};
        
        for(int i : nums)
            ++freq[i];
        
        int inc = 0, exc = 0;
        
        for(int i = 1; i <= 10000; i++){
            int ni = exc + freq[i] * i;
            int ne = max(inc, exc);
            
            inc = ni;
            exc = ne;
        }
        
        return max(inc, exc);
    }
};