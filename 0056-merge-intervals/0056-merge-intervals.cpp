class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>ans;
        
        sort(intervals.begin(), intervals.end());
        
        int start = -1, end = -1;
        
        for(int i = 0; i < intervals.size(); i++){       
            
            vector<int>curr = intervals[i];
            
            if(start == -1 && end == -1){
                
                start = curr[0], end = curr[1];
                
                continue;
            
            }
            
            if(end >= curr[0] && end <= curr[1])    end = curr[1];
            
            else if(start <= curr[0] && curr[1] <= end) continue;
            
            else{
                
                ans.push_back({start, end});
                
                start = curr[0], end = curr[1];
            }
            
        }
        
        if(start != -1 && end != -1)    ans.push_back({start, end});
        
        return ans;
        
    }
};