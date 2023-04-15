class Solution
{
    public:
        int findMaxConsecutiveOnes(vector<int> &nums)
        {
            int n = nums.size(), ans = 0, cur = 0, i = 0;
            while (i < n)
            {
                if(nums[i] == 1){
                    ++cur;
                    ans = max(ans, cur);
                }else{
                    cur = 0;
                }
                ++i;
            }
            ans = max(ans, cur);
            return ans;
        }
};