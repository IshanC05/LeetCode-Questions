class Solution {
public:
    bool helper(vector<int>&arr){
        
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int diff = arr[1] - arr[0];
        
        for(int i = 2; i < n; i++){
            
            if(arr[i] - arr[i - 1] != diff)     return false;
            
        }
        
        return true;
        
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int n = l.size();
        
        vector<bool>res(n);
        
        for(int i = 0; i < n; i++){
            
            int start = l[i], end = r[i];
            
            if(start == end){
                
                res[i] = false;
                
                continue;
                
            }
            
            vector<int>arr = {nums.begin() + start, nums.begin() + end + 1};
            
            res[i] = helper(arr);
            
        }
        
        return res;
        
    }
};