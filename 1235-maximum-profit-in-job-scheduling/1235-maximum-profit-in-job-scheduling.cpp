class Solution {
public:
    int t[50005];
    int helper(vector<vector<int>>&jobs, vector<int>& start, int idx){
        if(idx == jobs.size())    return 0;
        
        if(t[idx] != -1)    return t[idx];
        
        int nextIdx = lower_bound(start.begin(), start.end(), jobs[idx][1]) - start.begin();
        
        int take = jobs[idx][2] + helper(jobs, start, nextIdx);
        
        int skip = helper(jobs, start, idx + 1);
        
        return t[idx] = max(take, skip);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(t, -1, sizeof(t));
        
        int n = profit.size();
        
        vector<vector<int>>jobs;
        
        for(int i = 0; i < n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
              
        for(int i = 0; i < n; i++){
            startTime[i] = jobs[i][0];
        }
        
        return helper(jobs, startTime, 0);
    }
};