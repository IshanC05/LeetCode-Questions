class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<vector<int>>> adj;

        for (vector<int> edge : times) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }
        
        vector<int>result(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
     
        result[k] = 0;
        pq.push({result[k], k});
        
        while(!pq.empty()){
            
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            for(auto &edge : adj[u]){
                int adj = edge[0];
                int adjDist = edge[1];
                
                if(result[adj] > d + adjDist){
                    result[adj] = d + adjDist;
                    pq.push({result[adj], adj});
                }
            }
        }
        
        int res = -1;
        
        for(int i = 1; i <= n; i++){
            if(result[i] == INT_MAX)    return -1;
            res = max(res, result[i]);
        }
        
        return res;
    }
};