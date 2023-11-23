class Solution {
public:
    bool helper(vector<int>arr){
        
        int n = arr.size(), minE = INT_MAX, maxE = INT_MIN;
        
        unordered_set<int>st;
                
        for(auto i : arr){
            
            minE = min(minE, i);
            
            maxE = max(maxE, i);
                
            st.insert(i);
        }
        
        if((maxE - minE) % (n - 1) != 0)    return false;
        
        int diff = (maxE - minE) / (n - 1);
        
        int curr = minE + diff;
        
        while(curr < maxE){
            
            if(st.find(curr) == st.end())     return false;
            
            curr = curr + diff;
            
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