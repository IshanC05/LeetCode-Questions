class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<vector<int>>pairs;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            pairs.push_back({nums[i], i});
        }
        sort(pairs.begin(), pairs.end());
        int i = 0, j = n - 1;
        while(i < j){
            int curr = pairs[i][0] + pairs[j][0];
            if(curr == target){
                return {pairs[i][1], pairs[j][1]};
            }else if(curr < target){
                ++i;
            }else{
                --j;
            }
        }
        return {-1, -1};
    }
};