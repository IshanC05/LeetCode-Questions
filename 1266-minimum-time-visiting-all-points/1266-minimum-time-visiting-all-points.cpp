class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;

        for (int i = 0; i < n - 1; i++) {
            int X = points[i][0], Y = points[i][1];
            int x = points[i + 1][0], y = points[i + 1][1];

            while (X != x || Y != y) {
                if (X < x) X += 1;
                else if (X > x) X -= 1;

                if (Y < y) Y += 1;
                else if (Y > y) Y -= 1;

                ++res;
            }
        }

        return res;
    }
};