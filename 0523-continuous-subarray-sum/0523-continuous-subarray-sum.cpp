class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        long long prefixSum = 0;
        // bool ans = false;
        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            long long rem = prefixSum % k;
            if(rem == 0 and i + 1 >= 2){
                return true;
            }
            if(mp.find(rem) != mp.end()){
                if(i - mp[rem] >= 2){
                    return true;
                }
            }else{
                mp[rem] = i;    
            }
        }
        return false;
    }
};