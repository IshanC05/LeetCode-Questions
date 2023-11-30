class Solution {
public:
    int numSquares(int n) {
        
        vector<int> squares;
        
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }

        int N = squares.size();

        vector<vector<int>> dp(N + 1, vector<int>(n + 1, INT_MAX));

        for (int i = 0; i <= N; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= n; j++) {
                if (squares[i - 1] <= j) {
 
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - squares[i - 1]]);
                } else {
                    
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[N][n];
    }
};