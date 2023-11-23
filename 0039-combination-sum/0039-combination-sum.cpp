class Solution {
public:
    vector<vector<int>>res;
    
    void helper(vector<int>&input, int t, int n, vector<int>&output){
        
        if(n == 0 || t == 0){
            if(t == 0)  res.push_back(output);
            return;
        }
        
        if(input[n - 1] <= t){
            
            output.push_back(input[n - 1]);
            
            helper(input, t - input[n - 1], n, output);
            
            output.pop_back();
            
        }
        
        helper(input, t, n - 1, output);
            
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        res.clear();
        
        int n = candidates.size();
        
        vector<int>output;
        
        helper(candidates, target, n, output);
        
        return res;
    }
};