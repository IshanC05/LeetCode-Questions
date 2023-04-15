class Solution
{
    public:
        int findMaxConsecutiveOnes(vector<int> &nums)
        {
            int n = nums.size(), ans = 0, cur = 0, i = 0;
            while (i < n)
            {
                while (i < n and nums[i] == 1)
                {
                    ++cur;
                    ++i;
                }
                ans = max(ans, cur);
                cur = 0;
                ++i;
            }
            ans = max(ans, cur);
            return ans;
        }
};