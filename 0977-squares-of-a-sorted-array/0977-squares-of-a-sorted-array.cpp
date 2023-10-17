class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>ans(n);
        
        int i = 0, j = nums.size() - 1, k = j;
        
        while(i <= j){
            
            if(abs(nums[i]) > abs(nums[j])){
                ans[k--] = (nums[i] * nums[i]);
                ++i;
            }
            else {   
                ans[k--] = (nums[j] * nums[j]);
                --j;
            }
            
        }
        
        return ans;        
    }
};