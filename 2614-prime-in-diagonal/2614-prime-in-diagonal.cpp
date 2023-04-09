bool sieve[4000001] = { true, true};
class Solution
{
    public:
        void buildSieve()
        {
            for (int i = 2; i * i < 4000001; ++i)
            {
                if (!sieve[i])
                {
                    for (int j = i * i; j < 4000001; j += i)
                    {
                        sieve[j] = true;
                    }
                }
            }
        }
    int diagonalPrime(vector<vector < int>> &nums)
    {
        buildSieve();
        int n1 = 0, n2 = 0, ans = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            n1 = (!sieve[nums[i][i]]) ? nums[i][i] : 0;
            n2 = (!sieve[nums[i][n - i - 1]]) ? nums[i][n - i - 1] : 0;
            ans = max(ans, max(n1, n2));
        }
        
        return ans;
    }
};