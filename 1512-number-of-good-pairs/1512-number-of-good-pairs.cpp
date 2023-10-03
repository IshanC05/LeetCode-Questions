class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        
        for(int i : nums)
            ++mp[i];
        
        int count = 0;
        
        for(int i : nums){
            
            if(mp[i] > 1)   count += mp[i] - 1;
            
            --mp[i];
            
            if(mp[i] == 0)  mp.erase(i);
        }
        
        return count;
    }
};