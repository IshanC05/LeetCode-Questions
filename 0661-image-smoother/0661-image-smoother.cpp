class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n));

        int dx[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
        int dy[8] = {0, -1, -1, -1, 0, +1, +1, +1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int c = 1;
                int sum = img[i][j];

                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        ++c;
                        sum += img[x][y];
                    }
                }

                res[i][j] = floor(sum / (float)(c));
            }
        }
        return res;
    }
};