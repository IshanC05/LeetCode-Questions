class Solution
{
    public:
        int maximumDifference(vector<int> &nums)
        {
            int i = 0, j = 1, ans = -1, curAns = -1;
            while (j < nums.size())
            {
                if (nums[j] < nums[i])
                {
                    i = j;
                }
                else if(nums[j] > nums[i] and j != i){
                    curAns = max(curAns, nums[j] - nums[i]);
                    ans = curAns;
                }
                ++j;
            }
            return max(curAns, ans);
        }
};