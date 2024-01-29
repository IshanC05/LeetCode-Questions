class Solution {
public:
    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, -1, 0, +1};
    bool dfs(vector<vector<char>>& board, string &word, int r, int c, int i, int j, int idx){
        if(idx == word.size())  return true;
        
        int currChar = board[i][j];
        board[i][j] = '0';
        
        bool res = false;
        
        for(int k = 0; k < 4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(x >= 0 && x < r && y >= 0 && y < c && board[x][y] != '0' && board[x][y] == word[idx]){
                res = (res | dfs(board, word, r, c, x, y, idx + 1));
            }    
        }
        
        board[i][j] = currChar;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size(), c = board[0].size();
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                
                if(board[i][j] == word[0]){
                    if(dfs(board, word, r, c, i, j, 1))  return true;
                }
                
            }
        }
        
        return false;
    }
};