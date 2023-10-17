class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>ans(n);
        
        for(auto &it : nums)
            it = (it * it);
        
        int i = 0, j = nums.size() - 1, k = j;
        
        while(i <= j){
            
            if(nums[i] > nums[j])
                ans[k--] = nums[i++];
            
            else    ans[k--] = nums[j--];
            
        }
        
        return ans;        
    }
};