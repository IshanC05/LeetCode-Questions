class Solution {
public:
    unordered_map<string, vector<string>>adj;
    int numTickets;
    vector<string>result;
    
    bool dfs(string fromCity, vector<string>& path){
        
        path.push_back(fromCity);
        
        if(path.size() == numTickets + 1){
            result = path;
            return true;
        }
        
        vector<string>&neighbours = adj[fromCity];
        
        for(int i = 0; i < neighbours.size(); i++){
            
            string toCity = neighbours[i];
            
            neighbours.erase(neighbours.begin() + i);
            
            if(dfs(toCity, path) == true){
                return true;
            }
            
            neighbours.insert(neighbours.begin() + i, toCity);
            
        }
        
        path.pop_back();
        
        return false;      
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        numTickets = tickets.size();
        
        for(auto &cities : tickets){
            
            string u = cities[0];
            string v = cities[1];
            
            adj[u].push_back(v);
            
        }
        
        // sort the cities
        
        for(auto &it : adj){
            
            sort(it.second.begin(), it.second.end());
            
        }
        
        vector<string>path;
        
        dfs("JFK", path);
        
        return result;        
    }
};