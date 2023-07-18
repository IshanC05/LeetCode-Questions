class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>>Map;
        
        for(string str : strs){
            
            string tempStr = str;
            
            sort(str.begin(), str.end());
            
            if(Map.find(str) == Map.end()){
                
                vector<string>tempVector({tempStr});
                
                Map[str] = tempVector;
                
            }
            
            else   Map[str].push_back(tempStr);  
            
        }
        
        vector<vector<string>>ans;
        
        for(auto it = Map.begin(); it != Map.end(); it++){
            
            ans.push_back(it->second);
            
        }
        
        return ans;
        
    }
};