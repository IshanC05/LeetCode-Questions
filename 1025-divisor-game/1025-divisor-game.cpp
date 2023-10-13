class Solution {
public:
    bool helper(int n, bool &turn){
        
        if(n == 1)  return turn;
        
        turn = !turn;
        
        return helper(n - 1, turn);
    }
    
    bool divisorGame(int n) {
        
        // turn = true --> alice made the move
        // turn = false --> bob made the move
        bool turn = false;
        
        return helper(n, turn);
    }
};