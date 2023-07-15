class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int,int>freq;
        
        for(int i : arr)    ++freq[i];
        
        vector<pair<int,int>>temp;
        
        for(auto it = freq.begin(); it != freq.end(); it++){
            
            temp.push_back(make_pair(it->second, it->first));
            
        }
        
        sort(temp.begin(), temp.end());
        
        for(int i = 0; i < temp.size(); i++){
            
            pair<int,int>p1 = temp[i];
            
            if(p1.first <= k){
                
                k -= p1.first;
                
                freq.erase(p1.second);
                
            }
            
        }
        
        return freq.size();
        
    }
};