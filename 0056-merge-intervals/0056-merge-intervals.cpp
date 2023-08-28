class Solution {
public:
    bool static comp(vector<int>a, vector<int>b){
        
        if(a[0] == b[0])    return a[1] < b[1];
        
        return a[0] < b[0];
        
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<vector<int>>ans;
        
        int start = intervals[0][0], end = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++){
            
            int currStart = intervals[i][0], currEnd = intervals[i][1];
            
            if(currStart <= end){
                
                start = min(start, currStart);
                
                end = max(end, currEnd);
                
            }else{
                
                ans.push_back({start, end});
                
                start = currStart, end = currEnd;
                
            } 
        }
        
        ans.push_back({start, end});
        
        return ans;
        
    }
};