class Solution
{
    public:
        vector<int> smallestRange(vector<vector < int>> &nums)
        {
            int minx = 0;
            int miny = INT_MAX;
            int maxVal = INT_MIN;
            vector<int> next(nums.size(), 0);
            bool flag = true;

            auto compare =[& ](int i, int j)
            {
                return nums[i][next[i]] > nums[j][next[j]];
            };
            priority_queue<int, vector < int>, decltype(compare) > min_queue(compare);

            for (int i = 0; i < nums.size(); i++)
            {
                min_queue.push(i);
                maxVal = max(maxVal, nums[i][0]);
            }

            for (int i = 0; i < nums.size() && flag; i++)
            {
                for (int j = 0; j < nums[i].size() && flag; j++)
                {
                    int min_i = min_queue.top();
                    min_queue.pop();

                    if (miny - minx > maxVal - nums[min_i][next[min_i]])
                    {
                        minx = nums[min_i][next[min_i]];
                        miny = maxVal;
                    }

                    next[min_i]++;
                    if (next[min_i] == nums[min_i].size())
                    {
                        flag = false;
                        break;
                    }
                    min_queue.push(min_i);
                    maxVal = max(maxVal, nums[min_i][next[min_i]]);
                }
            }

            return {
                minx,
                miny
            };
        }
};