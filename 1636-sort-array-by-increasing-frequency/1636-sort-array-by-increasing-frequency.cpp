class Solution {
public:
    
    bool static compare(pair<int,int>a, pair<int,int>b){
        
        if(a.first == b.first){
            
            if(a.second > b.second) return true;
            
            return false;
            
        }else{
            
            if(a.first < b.first)   return true;
        }
        
        return false;
                   
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        
        for(int i : nums)   ++mp[i];
        
        vector<pair<int,int>>temp;
        
        for(auto it : mp){
            
            temp.push_back({it.second, it.first});
            
        }
        
        sort(temp.begin(), temp.end(), compare);
        
        int k = 0;
        
        for(int i = 0; i < temp.size(); i++){
            
            while(temp[i].first){
                
                nums[k++] = temp[i].second;
                
                --temp[i].first;
                
            }
            
        }
        
        return nums;
        
    }
};