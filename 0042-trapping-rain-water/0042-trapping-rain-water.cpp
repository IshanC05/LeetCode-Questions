class Solution
{
    public:
        int trap(vector<int> &height)
        {
            vector<int> leftMax(height.size());
            vector<int> rightMax(height.size());
            int l = height[0], r = height[height.size() - 1];
            leftMax[0] = l;
            rightMax[rightMax.size() - 1] = r;
            for (int i = 1; i < height.size(); i++)
            {
                l = max(l, height[i]);
                leftMax[i] = l;
            }
            for (int i = height.size() - 2; i >= 0; i--) {
                r = max(r, height[i]);
                rightMax[i] = r;
            }
            int res = 0;
            for(int i=0;i<height.size();i++){
                res = res + min(leftMax[i], rightMax[i]) - height[i];
            }
            return res;
        }
};