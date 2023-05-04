class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int>freq;
        for(int i : nums){
            ans = ans + freq[i - k] + freq[i + k];
            ++freq[i];
        }
        return ans;
    }
};