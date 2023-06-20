class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0){
            return nums;
        }
        int windowLen = 2*k + 1, n = nums.size();
        vector<int>ans(n, -1);
        if(windowLen > n){
            return ans;
        }
        long long i = 0, j = 0, mid = 0, sum = 0;
        while(j < n){
            sum += nums[j];
            long long curLen = j - i + 1;
            if(curLen < windowLen){
                ++j;
            }else if(curLen == windowLen){
                mid = i + (j - i) / 2;
                ans[mid] = sum / windowLen;
                sum -= nums[i];
                ++i;
                ++j;
            }
        }
        return ans;
    }
};