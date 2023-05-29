class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>pairSet;
        for(int i = 0; i < nums.size(); i++){
            pairSet.push_back({nums[i], i});
        }
        
        sort(pairSet.begin(), pairSet.end());
 
        int i = 0, j = pairSet.size() - 1;
        while(i < j){
            long long sum = pairSet[i].first + pairSet[j].first;
            if(sum == target){
                return {pairSet[i].second, pairSet[j].second};
            }else if(sum < target){
                ++i;
            }else{
                --j;
            }
        }
        return {-1, -1};
    }
};