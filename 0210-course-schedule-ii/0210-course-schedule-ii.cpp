class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        // form graph
        vector<int>inDeg(n, 0);
        unordered_map<int,vector<int>>adj;
        for(vector<int>&c : prerequisites){
            
            int u = c[1];
            int v = c[0];
            
            adj[u].push_back(v);
            ++inDeg[v];
        }
        
        // add inDegree = 0 to queue
        int count = 0;
        vector<int>ans;
        queue<int>q;
        
        for(int i = 0; i < n; i++){
            if(inDeg[i] == 0){
                ++count;
                q.push(i);
            }
        }
        
        // Simple BFS for Kahn's
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int &v : adj[u]){
                --inDeg[v];
                
                if(inDeg[v] == 0){
                    ++count;
                    q.push(v);
                }
            }
            
            ans.push_back(u);
        }
        
        if(count == n){
            return ans;
        }
        
        return {};
    }
};