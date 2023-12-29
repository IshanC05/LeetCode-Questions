class Solution {
public:
    int t[11][1001];
    int helper(vector<int>& jobs, int d, int idx, int n){
        if(d == 1){
            int res = jobs[idx];
            for(int i = idx; i < n; i++){
                res = max(res, jobs[i]);
            }
            return res;
        }
        
        if(t[d][idx] != -1) return t[d][idx];
        
        int maxD = jobs[idx], finalRes = INT_MAX;
        
        for(int i = idx; i <= n - d; i++){
            maxD = max(maxD, jobs[i]);
            int res = maxD + helper(jobs, d - 1, i + 1, n);
            finalRes = min(finalRes, res);
        }
        
        return t[d][idx] = finalRes;
    }
    
    int minDifficulty(vector<int>& jobs, int d) {
        int n = jobs.size();
        if(n < d)   return -1;
        memset(t, -1, sizeof(t));
        return helper(jobs, d, 0, n);
    }
};