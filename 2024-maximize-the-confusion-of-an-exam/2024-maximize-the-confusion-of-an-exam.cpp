class Solution
{
    public:

        int helper(string &s, int k, char a, char b)
        {

            int i = 0, j = 0, n = s.size();

            int ans = 0, count = 0;

            while (j < n)
            {

                if (s[j] == b)
                {
                    ++count;
                }

                while (count > k)
                {
                    if (s[i] == b) --count;

                    ++i;
                }

                ans = max(ans, j - i + 1);
                
                ++j;
            }

            return ans;
        }

    int maxConsecutiveAnswers(string answerKey, int k)
    {

        int smallAns1 = helper(answerKey, k, 'T', 'F');

        int smallAns2 = helper(answerKey, k, 'F', 'T');

        return max(smallAns1, smallAns2);
    }
};