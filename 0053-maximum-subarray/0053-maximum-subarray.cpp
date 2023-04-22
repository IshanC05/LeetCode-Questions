class Solution
{
    public:
        int maxSubArray(vector<int> &nums)
        {
            int curSum = nums[0], ans = nums[0], j = 1, n = nums.size();
            while (j < n)
            {
                curSum = max(nums[j], curSum + nums[j]);
                ans = max(curSum, ans);
                ++j;
            }
            return ans;
        }
};