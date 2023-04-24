class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {
            int n = nums.size(), prod = 1;
            vector<int> left(n, 0);
            vector<int> right(n, 0);

            left[0] = prod, right[n - 1] = prod;
            for (int i = 1; i < n; i++)
            {
                prod = prod *nums[i - 1];
                left[i] = prod;
            }
            prod = 1;
            for (int i = n - 2; i >= 0; i--)
            {
                prod = prod *nums[i + 1];
                right[i] = prod;
            }
            vector<int> ans(n);
            for (int i = 0; i < n; i++)
            {
                ans[i] = left[i] *right[i];
            }
            return ans;
        }
};