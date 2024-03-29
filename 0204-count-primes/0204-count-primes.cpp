class Solution
{
    public:
        int countPrimes(int n)
        {
            if (n < 3)
            {
                return 0;
            }
            vector<bool> isPrime(n + 1, true);
            for (int i = 2; i * i <= n; i++)
            {
                if (isPrime[i])
                {
                    for (int j = i * i; j <= n; j = j + i)
                    {
                        isPrime[j] = false;
                    }
                }
            }
            int ans = 0;
            for (int i = 2; i < n; i++)
            {
                ans = (isPrime[i]) ? ++ans : ans;
            }
            return ans;
        }
};