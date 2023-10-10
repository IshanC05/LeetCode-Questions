class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& t) {
        
        sort(p.begin(), p.end());
        sort(t.rbegin(), t.rend());
        
        int minTime = INT_MIN, j = 0;
        
        for(int i = 0; i < p.size(); i++){
            
            minTime = max(minTime, p[i] + t[j]);
            
            j += 4;
        }
        
        return minTime;        
    }
};