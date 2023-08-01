class Solution {
public:
    
    vector<vector<int>>ans;
    
    void helper(vector<int>&current, int start, int n, int k){
        
        if(current.size() == k){
            
            ans.push_back(current);
            
            return;
            
        }
        
        for(int i = start; i < n + 1; i++){
            
            current.push_back(i);
            
            helper(current, i + 1, n, k);
            
            current.pop_back();
            
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        ans.clear();
        
        vector<int>current;
        
        helper(current, 1, n, k);
        
        return ans;
    }
};