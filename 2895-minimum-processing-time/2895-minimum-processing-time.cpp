class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& t) {
        
        sort(p.begin(), p.end());
        sort(t.rbegin(), t.rend());
        
        int minTime = INT_MIN, j = 0;
        
        for(int i = 0; i < p.size(); i++){
            
            int minTimeI = INT_MIN;
            
            for(int k = 0; k < 4; k++){
                
                minTimeI = max(minTimeI, p[i] + t[j]);
                
                ++j;
                
            }
            
            minTime = max(minTime, minTimeI);
        }
        
        return minTime;        
    }
};