class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<long,vector<int>>, vector<pair<long,vector<int>>>, greater<pair<long,vector<int>>>>pq;
        
        int i;
        
        for(i = 0; i < points.size(); i++){
            
            long dist = (long)(points[i][0]) * (points[i][0]) + (points[i][1]) * (points[i][1]);
            
            pq.push({dist, {points[i][0], points[i][1]}});
            
        }
        
        
        vector<vector<int>>ans(k);
        
        i = 0;
        
        while(k--){
            
            ans[i++] = pq.top().second;
            
            pq.pop();
            
        }
        
        return ans;
        
    }
};