class Solution
{
    public:
        string mergeAlternately(string word1, string word2)
        {
            string ans = "";
            int m = word1.size(), n = word2.size();
            int i = 0, j = 0;
            bool chance = true;
            while (i < m and j < n)
            {
                if (chance)
                {
                    ans.push_back(word1[i++]);
                }
                else
                {
                    ans.push_back(word2[j++]);
                }
                chance = !chance;
            }
            while (i < m)
            {
                ans.push_back(word1[i++]);
            }
            while (j < n)
            {
                ans.push_back(word2[j++]);
            }
            return ans;
        }
};