class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for(int i = 0; i < nums.size(); i++){
            sort(nums[i].begin(), nums[i].end());
            // reverse(nums[i].begin(), nums[i].end());
        }
        int m = nums.size(), n = nums[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int maxElem = 0;
            for(int j = 0; j < m; j++){
                if(maxElem < nums[j][i]){
                    maxElem = nums[j][i];
                }
            }
            ans = ans + maxElem;
        }
        return ans;
    }
};