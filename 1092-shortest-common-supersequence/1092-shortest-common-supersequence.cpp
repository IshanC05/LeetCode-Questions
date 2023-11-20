class Solution {
public:
    string shortestCommonSupersequence(string X, string Y) {
        
        int m = X.size(), n = Y.size();
        
        vector<vector<int>>t(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){

                if(X[i - 1] == Y[j - 1]){

                    t[i][j] = 1 + t[i - 1][j - 1];

                }else{

                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);

                }

            }
        }

        int i = m, j = n;

        string res = "";

        while(i > 0 && j > 0){

            if(X[i - 1] == Y[j - 1]){
                res.push_back(X[i - 1]);
                --i;
                --j;
            }else if(t[i - 1][j] > t[i][j - 1]){
                res.push_back(X[i - 1]);
                --i;
            }else{
                res.push_back(Y[j - 1]);
                --j;
            }
        }
        
        while(i > 0){
            res.push_back(X[i - 1]);
            --i;
        }
        
        while(j > 0){
            res.push_back(Y[j - 1]);
            --j;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
        
    }
};