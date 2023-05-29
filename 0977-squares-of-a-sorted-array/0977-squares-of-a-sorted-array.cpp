class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n - 1;
        
        for(int k = 0; k < n; k++){
            nums[k] = nums[k] * nums[k];
        }
        
        int k = n - 1;
        vector<int>ans(n, 0);
        
        while(i <= j){
            if(nums[i] <= nums[j]){
                ans[k] = nums[j--];
            }else{
                ans[k] = nums[i++];
            }
            --k;
        }
        return ans;
    }
};