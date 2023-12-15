class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        unordered_set<string>sources;
        
        for(vector<string> path : paths){
            
            string u = path[0];            
            sources.insert(u);
            
        }
        
        for(vector<string>path : paths){
            
            string u = path[0];
            string v = path[1];
            
            if(sources.find(u) == sources.end())    return u;
            
            if(sources.find(v) == sources.end())    return v;
            
        }
        
        return "";
        
    }
};