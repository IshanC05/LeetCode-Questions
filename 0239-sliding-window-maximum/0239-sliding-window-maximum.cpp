class Solution
{
    public:
        vector<int> nextGreater(vector<int> &nums)
        {
            int n = nums.size();
            stack<int> s;
            vector<int> res(n);

            for (int i = n - 1; i >= 0; i--)
            {
                while (!s.empty() and nums[s.top()] <= nums[i])
                {
                    s.pop();
                }
                if (s.empty())
                    res[i] = n;
                else
                    res[i] = s.top();

                s.push(i);
            }
            return res;
        }

    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        vector<int> temp = nextGreater(nums);
        int n = nums.size();

        int j = 0;

        for (int i = 0; i <= n - k; i++)
        {
            if (j < i)
            {
                j = i;
            }
            while (temp[j] < i + k)
            {
                j = temp[j];
            }

            ans.push_back(nums[j]);
        }

        return ans;
    }
};