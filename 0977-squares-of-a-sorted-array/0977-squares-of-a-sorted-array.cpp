class Solution
{
    public:
        vector<int> sortedSquares(vector<int> &nums)
        {
            int n = nums.size(), i = 0, j = n - 1, k = n - 1;
            vector<int> ans(n);
            for (int x = 0; x < n; x++)
            {
                nums[x] = nums[x] *nums[x];
            }
            while (k >= 0)
            {
                if (nums[i] > nums[j])
                {
                    ans[k--] = nums[i++];
                }
                else
                {
                    ans[k--] = nums[j--];
                }
            }
            return ans;
        }
};