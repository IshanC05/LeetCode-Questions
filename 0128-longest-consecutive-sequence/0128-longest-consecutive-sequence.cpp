class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            unordered_map<int, bool> present, checked;
            for (int i: nums)
            {
                present[i] = true;
            }
            int maxLength = 0;
            for (int x: nums)
            {
                if (!present[x - 1] and!checked[x])
                {
                    int curr = 0;
                    while (present[x])
                    {
                        ++curr;
                        checked[x] = true;
                        ++x;
                    }
                    maxLength = max(maxLength, curr);
                }
            }
            return maxLength;
        }
};