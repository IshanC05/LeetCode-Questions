unordered_map<int,int>mp;

class Solution {    
public:
    
    bool static compare(int a, int b){
        
        if(mp[a] == mp[b]){
            
            if(a > b) return true;
            
            return false;
            
        }
        
        return mp[a] < mp[b];
                   
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        
        mp.clear();
        
        for(int i : nums)   ++mp[i];

        sort(nums.begin(), nums.end(), compare);
        
        return nums;
        
    }
};