class Solution {
    int dx[] = {-1, 0, +1, 0};
    int dy[] = {0, -1, 0, +1};
    
    public boolean dfs(char[][] board, String word, int r, int c, int i, int j, int idx){
        if(idx == word.length())  return true;
        
        char currChar = board[i][j];
        board[i][j] = '0';
        
        boolean res = false;
        
        for(int k = 0; k < 4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(x >= 0 && x < r && y >= 0 && y < c && board[x][y] != '0' && board[x][y] == word.charAt(idx)){
                res = (res | dfs(board, word, r, c, x, y, idx + 1));
            }    
        }
        
        board[i][j] = currChar;
        return res;
    }

    public boolean exist(char[][] board, String word) {
        int r = board.length, c = board[0].length;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                
                if(board[i][j] == word.charAt(0)){
                    if(dfs(board, word, r, c, i, j, 1))  return true;
                }
                
            }
        }
        
        return false;        
    }
}