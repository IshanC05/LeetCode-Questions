class Solution {
public:
    
    void dfs(vector<vector<int>>& arr, int m, int n, int i, int j, int c1, int c2) {
        if (i >= m || i < 0 || j >= n || j < 0 || arr[i][j] != c1)
            return;

        arr[i][j] = c2;

        dfs(arr, m, n, i + 1, j, c1, c2);
        dfs(arr, m, n, i - 1, j, c1, c2);
        dfs(arr, m, n, i, j + 1, c1, c2);
        dfs(arr, m, n, i, j - 1, c1, c2);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();

        if (image[sr][sc] != newColor) {
            dfs(image, m, n, sr, sc, image[sr][sc], newColor);
        }

        return image;
    }


};