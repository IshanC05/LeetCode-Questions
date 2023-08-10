class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int,int>freq;
        
        for(int i : nums)   ++freq[i];
        
        int target = nums.size() / 3;
        
        vector<int>ans;
        
        for(auto it : freq){
            
            if(it.second > target) ans.push_back(it.first);
            
        }
        
        return ans;
        
    }
};