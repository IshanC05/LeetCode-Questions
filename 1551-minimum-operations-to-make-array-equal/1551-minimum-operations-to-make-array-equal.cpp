class Solution
{
    public:
        int minOperations(int n)
        {
            return ((n - n % 2) *((n + 1) / 2)) / 2;
        }
};