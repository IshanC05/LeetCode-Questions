class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<float>time(n);
        
        for(int i = 0; i < n; i++){
            time[i] = (dist[i] / (speed[i] * 1.0));
        }
        
        sort(time.begin(), time.end());
        
        int count = 0, passedTime = 0;
        
        for(int i = 0; i < n; i++){
            
            if(time[i] <= passedTime)   break;
            
            ++count;
            
            ++passedTime;
            
        }
        
        return count;
        
    }
};