class Solution {
public:
    bool static cmp(vector<int>a, vector<int>b){
        return a[0] < b[0];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end());
        
        int ans = 1;
        
        int s = points[0][0], e = points[0][1];
        
        for(int i = 1; i < points.size(); i++){
            
            int cs = points[i][0], ce = points[i][1];
            
            if(cs <= e){
                
                s = max(s, cs);
                
                e = min(e, ce);
                
            }
            
            else{
                
                ++ans;
                
                s = cs, e = ce;
                
            }
            
        }
        
        return ans;
        
    }
};