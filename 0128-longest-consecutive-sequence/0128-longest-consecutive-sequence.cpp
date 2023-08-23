class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int>mp, checked;
        
        for(int i : nums)   ++mp[i];
        
        int maxLen = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(checked.find(nums[i]) == checked.end()){
                
                int curLen = 0, start = nums[i], end = nums[i];
                
                while(mp.find(start) != mp.end()){
                    
                    ++curLen;
                    
                    --start;
                    
                    ++checked[start];
                }
                
                
                while(mp.find(end + 1) != mp.end()){
                    
                    ++curLen;
                    
                    ++end;
                    
                    ++checked[end];
                }
                
                maxLen = max(maxLen, curLen);
                
            }
            
        }
        
        return maxLen;
        
    }
};