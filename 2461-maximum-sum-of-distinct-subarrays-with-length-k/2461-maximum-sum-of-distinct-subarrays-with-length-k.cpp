class Solution
{
    public:
        long long maximumSubarraySum(vector<int> &nums, int k)
        {
            int i = 0, j = 0, n = nums.size();
            long long curAns = 0, ans = 0;
            unordered_set<int> freqSet;
            while (j < n)
            {
                while (j - i + 1 > k || freqSet.count(nums[j]))
                {
                    curAns = curAns - nums[i];
                    freqSet.erase(nums[i]);
                    ++i;
                }
                curAns = curAns + nums[j];
                if (j - i + 1 == k)
                {
                    ans = max(ans, curAns);
                }
                freqSet.insert(nums[j]);
                ++j;
            }
            return ans;
        }
};