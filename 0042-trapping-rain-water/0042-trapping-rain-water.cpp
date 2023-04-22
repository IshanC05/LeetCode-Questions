class Solution
{
    public:
        int trap(vector<int> &height)
        {
            int n = height.size();
            vector<int> leftMax(n);
            vector<int> rightMax(n);
            int l = height[0], r = height[n - 1];
            leftMax[0] = l;
            rightMax[n - 1] = r;
            for (int i = 1; i < n; i++)
            {
                l = max(l, height[i]);
                leftMax[i] = l;
            }
            for (int i = n - 2; i >= 0; i--)
            {
                r = max(r, height[i]);
                rightMax[i] = r;
            }
            int res = 0;
            for (int i = 0; i < n; i++)
            {
                res = res + min(leftMax[i], rightMax[i]) - height[i];
            }
            return res;
        }
};