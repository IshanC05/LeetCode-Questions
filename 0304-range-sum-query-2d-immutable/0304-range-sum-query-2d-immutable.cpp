class NumMatrix {
private:
    vector<vector<int>> arr;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        arr = vector<vector<int>>(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int a = (i > 0) ? arr[i - 1][j] : 0;
                int b = (j > 0) ? arr[i][j - 1] : 0;
                int c = (i > 0 && j > 0) ? arr[i - 1][j - 1] : 0;
                arr[i][j] = a + b - c + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = (row1 > 0 && col1 > 0) ? arr[row1 - 1][col1 - 1] : 0;
        int b = (row1 > 0) ? arr[row1 - 1][col2] : 0;
        int c = (col1 > 0) ? arr[row2][col1 - 1] : 0;
        int d = arr[row2][col2];

        return d - b - c + a;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */