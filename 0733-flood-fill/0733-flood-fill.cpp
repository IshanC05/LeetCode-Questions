class Solution {
public:
    int rows[4] = {0, -1, 0, +1};
    int cols[4] = {-1, 0, +1, 0};

    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    void dfs(vector<vector<int>>& image, int startRow, int startCol, int m, int n, int startColor, int newColor) {
        image[startRow][startCol] = newColor;

        for (int i = 0; i < 4; i++) {
            int newRow = startRow + rows[i];
            int newCol = startCol + cols[i];

            if (isValid(newRow, newCol, m, n) && image[newRow][newCol] == startColor) {
                dfs(image, newRow, newCol, m, n, startColor, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        int startColor = image[sr][sc];

        if (startColor == newColor) return image;  

        dfs(image, sr, sc, m, n, startColor, newColor);

        return image;
    }
};