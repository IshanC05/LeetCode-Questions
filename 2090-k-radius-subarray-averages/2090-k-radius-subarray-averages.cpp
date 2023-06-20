class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int windowLen = 2 * k + 1, n = nums.size();
        vector<int>ans(n, -1);
        
        if(k == 0) return nums;
        if(windowLen > n) return ans;
        
        vector<long long>prefix(n, 0);
        prefix[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }
        
        for(int i = 0; i < n; i++){
            int l = i - k, r = i + k;
            if(l < 0 || r >= n){
                continue;
            }else{
                if(l == 0){
                    ans[i] = prefix[r] / windowLen;
                }else{
                    ans[i] = (prefix[r] - prefix[l - 1]) / windowLen;
                }
            }
        }
        
        return ans;
    }
};