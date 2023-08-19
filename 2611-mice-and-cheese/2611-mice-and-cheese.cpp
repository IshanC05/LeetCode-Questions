class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        
        int n = reward1.size();
        
        vector<pair<int,int>>diff(n);
        
        for(int i = 0; i < n; i++){
            
            diff[i] = make_pair(reward1[i] - reward2[i], i);
            
        }
        
        sort(diff.rbegin(), diff.rend());
        
        int ans = 0;
        
        for(int i = 0; i < k; i++){
            
            ans += reward1[diff[i].second];
            
            reward2[diff[i].second] = 0;
            
        }
        
        for(int i : reward2)    ans += i;
        
        return ans;
        
    }
};