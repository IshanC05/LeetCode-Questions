class Solution {
public:
    void helper(vector<int>& nums, vector<int>input, int n, vector<vector<int>>&res, int prev){
        
        if(n == 0){
            res.push_back(input);
            return;
        }
        
        while(n > 0 && nums[n - 1] == prev)     
            --n;
        
        if(n == 0)  return;
        
        input.push_back(nums[n - 1]);
        
        helper(nums, input, n - 1, res, nums[n - 1]);
        
        input.pop_back();
        
        helper(nums, input, n - 1, res, prev);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>>res;
        
        vector<int>input;
        
        int n = nums.size();
        
        helper(nums, input, n, res, -100);
        
        return res;
    }
};