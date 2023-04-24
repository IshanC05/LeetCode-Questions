class Solution
{
    public:
        int maxPower(string s)
        {
            int i = 0, j = 1, res = 1, n = s.size();
            if (n == 1)
            {
                return res;
            }
            while (j < n)
            {
                while (j < n and s[i] == s[j])
                {
                    res = max(res, j - i + 1);
                    ++j;
                }
                i = j;
                ++j;
            }
            return res;
        }
};