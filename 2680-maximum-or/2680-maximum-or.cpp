class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefix(n + 1, 0), suffix(n + 1, 0);
        prefix[0] = 0, suffix[n] = 0;
        
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] | nums[i];
        }
        
        for(int i = n - 1; i >= 0; --i){
            suffix[i] = suffix[i + 1] | nums[i];
        }
        
        long long res = 0, p = 1;
        p = p << k;
        
        for(int i = 0; i < n; i++){
            res = max(res, (prefix[i] | (nums[i] * p) | suffix[i + 1]));
        }
        return res;
    }
};