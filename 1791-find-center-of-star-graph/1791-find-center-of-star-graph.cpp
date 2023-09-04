class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        // create graph
        unordered_map<int, vector<int>>mp;
        
        int ans = 0, ansEdge = 0;
        
        for(auto edge : edges){
            
            int u = edge[0];
            int v = edge[1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
            
            if(ansEdge < mp[u].size()){
                
                ansEdge = mp[u].size();
                
                ans = u;
                
            }
            
            if(ansEdge < mp[v].size()){
                
                ansEdge = mp[v].size();
                
                ans = v;
                
            }
            
        }
        
        return ans;
        
    }
};