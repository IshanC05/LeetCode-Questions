class Solution {
public:
    void helper(vector<int>& nums, vector<int>input, int n, set<vector<int>>&res){
        
        if(n == 0){
            res.insert(input);
            return;
        }
        
        input.push_back(nums[n - 1]);
        
        helper(nums, input, n - 1, res);
        
        input.pop_back();
        
        helper(nums, input, n - 1, res);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        set<vector<int>>res;
        
        vector<int>input;
        
        int n = nums.size();
        
        helper(nums, input, n, res);
        
        vector<vector<int>>ans(res.begin(), res.end());
        
        return ans;
    }
};