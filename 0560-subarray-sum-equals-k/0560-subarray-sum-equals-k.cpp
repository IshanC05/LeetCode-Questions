class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long,long long>mp;
        long long curr = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            curr = curr + nums[i];
            if(curr == k){
                ++ans;
            }
            long long target = curr - k;
            if(mp.find(target) != mp.end()){
                ans = ans + mp[target];
            }
            ++mp[curr];
        }
        return ans;
    }
};