class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int X = points[0][0], Y = points[0][1];
        int res = 0;

        for (int i = 1; i < n; i++) {
            int x = points[i][0], y = points[i][1];

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