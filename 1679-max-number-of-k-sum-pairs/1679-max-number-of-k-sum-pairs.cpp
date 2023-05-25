class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            int target = k - nums[i];
            if(mp.find(target) != mp.end()){
                ++res;
                --mp[target];
                if(mp[target] <= 0){
                    mp.erase(target);
                }
            }else{
                ++mp[nums[i]];
            }
        }
        return res;
    }
};