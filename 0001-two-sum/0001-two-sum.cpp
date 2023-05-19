class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>pairs;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            pairs.push_back(make_pair(nums[i], i));
        }
        sort(pairs.begin(), pairs.end());
        int i = 0, j = n - 1;
        while(i < j){
            int curr = pairs[i].first + pairs[j].first;
            if(curr == target){
                return {pairs[i].second, pairs[j].second};
            }else if(curr < target){
                ++i;
            }else{
                --j;
            }
        }
        return {-1, -1};
    }
};