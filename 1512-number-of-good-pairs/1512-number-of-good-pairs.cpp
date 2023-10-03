class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        
        int count = 0;
        
        for(int i : nums)
            count += mp[i]++;
                
        return count;
    }
};