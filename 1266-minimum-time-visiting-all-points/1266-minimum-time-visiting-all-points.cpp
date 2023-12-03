class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int res = 0;
        
        for(int i = 0; i < points.size() - 1; i++){
            
            int X = points[i][0], Y = points[i][1];
            
            int x = points[i + 1][0], y = points[i + 1][1];
            
            res += max(abs(X - x), abs(Y - y));
            
        }
        
        return res;
        
    }
};