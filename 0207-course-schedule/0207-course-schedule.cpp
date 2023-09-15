class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        
        // form graph + find degree         
        vector<int>inDeg(n, 0);
        unordered_map<int,vector<int>>adj;
        for(vector<int> &course : prerequisites){
            
            int u = course[1];
            int v = course[0];
            
            adj[u].push_back(v);
            ++inDeg[v];
        }
        
        // Add nodes with inDeg = 0 to q
        int count = 0;
        queue<int>q;
        for(int i = 0; i < n; i++){
            if(inDeg[i] == 0){
                ++count;
                q.push(i);
            }
        }
        
        // BFS using Kahn's
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
        }
        
        return (count == n);       
    }
};