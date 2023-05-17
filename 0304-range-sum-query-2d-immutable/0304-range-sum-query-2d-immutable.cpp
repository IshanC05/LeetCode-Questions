class NumMatrix
{
    public:
    vector<vector < int>> prefixSum;
    NumMatrix(vector<vector < int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        prefixSum.resize(m + 1);
        for (int i = 0; i <= m; i++)
        {
            prefixSum[i].resize(n + 1, 0);
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0) continue;
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        row1++, row2++, col1++, col2++;
        return prefixSum[row2][col2] - prefixSum[row2][col1 - 1] - prefixSum[row1 - 1][col2] + prefixSum[row1 - 1][col1 - 1];
    }
};

/**
 *Your NumMatrix object will be instantiated and called as such:
 *NumMatrix* obj = new NumMatrix(matrix);
 *int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */