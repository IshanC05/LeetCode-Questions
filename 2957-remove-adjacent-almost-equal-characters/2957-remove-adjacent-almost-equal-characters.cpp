class Solution {
public:
    bool check(char a, char b){
        return abs(a - b) <= 1;
    }
    
    int removeAlmostEqualCharacters(string word) {
        
        int res = 0, n = word.size(), i = 1;
        
        while(i < n){
            
            if(check(word[i], word[i - 1])){
                
                ++res;
                
                i += 2;
                
            }else   ++i;
            
        }
        
        return res;
        
    }
};