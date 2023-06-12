class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<vector<int>>temp;
        int ans = 0;
        for(int i : reward2){
            ans += i;
        }
        
        for(int i = 0; i < n; i++){
            temp.push_back({reward1[i] - reward2[i], i});
        }
        
        sort(temp.rbegin(), temp.rend());
        
        for(int j = 0; j < k; j++){
            int idx = temp[j][1];
            ans -= reward2[idx];
            ans += reward1[idx];
        }
        
        return ans;
    }
};