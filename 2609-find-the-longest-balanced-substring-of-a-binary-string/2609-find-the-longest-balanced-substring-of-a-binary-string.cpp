class Solution
{
    public:
        int findTheLongestBalancedSubstring(string s)
        {
            int ans = 0;
            for (int i = 0; i < s.size();)
            {
                int c0 = 0, c1 = 0;
                while (i < s.size() and s[i] == '0')
                {
                    ++i;
                    ++c0;
                }
                while (i < s.size() and s[i] == '1')
                {
                    ++i;
                    ++c1;
                }
                ans = max(ans, 2 * min(c0, c1));
            }
            return ans;
        }
};