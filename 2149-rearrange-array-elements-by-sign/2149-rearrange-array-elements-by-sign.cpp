class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        vector<int>ans(n, 0);
        int k = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[k] = nums[i];
                k = k + 2;
            }
        }
        k = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                ans[k] = nums[i];
                k = k + 2;
            }
        }
        return ans;
    }
};