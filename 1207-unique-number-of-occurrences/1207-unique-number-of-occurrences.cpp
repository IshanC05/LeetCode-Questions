class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int,int>mp;
        
        unordered_set<int>freqSet;
        
        for(int i : arr)    ++mp[i];
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            
            if(freqSet.find(it->second) == freqSet.end())
                
                freqSet.insert(it->second);
            
            else
                
                return false;
            
        }
        
        return true;
        
    }
};