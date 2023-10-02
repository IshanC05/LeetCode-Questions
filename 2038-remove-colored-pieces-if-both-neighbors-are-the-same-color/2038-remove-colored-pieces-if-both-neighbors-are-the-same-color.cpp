class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int n = colors.size();
        
        int countA = 0, countB = 0;
        
        if(n < 3)   return false;
        
        for(int i = 0; i < n - 2; i++){
            
            char a = colors[i], b = colors[i + 1], c = colors[i + 2];
            
            if(a == b && b == c && a == 'A')    ++countA;
            
            else if(a == b && b == c && a == 'B')    ++countB;
            
        }
        
        if(countA > countB)     return true;
        
        return false; 
        
    }
};