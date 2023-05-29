class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>>temp;
        if(n < 4){
            vector<vector<int>>ans;
            return ans;
        }
        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                int k = j + 1, l = nums.size() - 1;
                long long m = target;
                long long t = m - nums[i] - nums[j];
                while(k < l){
                    long long curr = nums[k] + nums[l];
                    if(curr == t){
                        temp.insert({nums[i], nums[j], nums[k], nums[l]});
                        ++k;
                        --l;
                    }else if(curr < t){
                        ++k;
                    }else{
                        --l;
                    }
                }
            }
        }
        vector<vector<int>>ans(temp.begin(), temp.end());
        return ans;
    }
};