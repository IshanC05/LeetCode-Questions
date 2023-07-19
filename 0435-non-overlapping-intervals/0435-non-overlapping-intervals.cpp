    bool cmpSecond(vector<int> &a, vector<int> &b)
    {

        return a[1] < b[1];
    }

    class Solution
    {
        public:
            int eraseOverlapIntervals(vector<vector < int>> &intervals)
            {

                sort(intervals.begin(), intervals.end(), cmpSecond);

                int start = -1, end = -1, ans = 0, k = INT_MIN;

                for (vector<int> curr: intervals)
                {

                    start = curr[0];

                    end = curr[1];

                    if (start >= k) k = end;

                    else ++ans;
                }

                return ans;
            }
    };