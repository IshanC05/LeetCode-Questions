class Solution
{
    public:
        void sortColors(vector<int> &nums)
        {
            int z = 0, t = 0;
            for (int x: nums)
            {
                if (x == 0)
                {
                    ++z;
                }
                if (x == 2)
                {
                    ++t;
                }
            }
            for (int i = 0; i < nums.size(); i++)
            {
                nums[i] = 1;
            }
            int i = 0, j = nums.size() - 1;
            while (z--)
            {
                nums[i++] = 0;
            }
            while (t--)
            {
                nums[j--] = 2;
            }
        }
};