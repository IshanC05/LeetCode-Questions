class Solution {
public:    
    int removeAlmostEqualCharacters(string word) {
        
        int res = 0, n = word.size(), i = 1;
        
        while(i < n){
            
            if(abs(word[i] - word[i - 1]) <= 1){
                
                ++res;
                
                i += 2;
                
            }
            
            else   ++i;
            
        }
        
        return res;
        
    }
};