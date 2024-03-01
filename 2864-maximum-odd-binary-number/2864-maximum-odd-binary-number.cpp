class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0, n = s.length();
        
        for(char &i : s){
            ones = (i == '1' ? ++ones : ones);
            i = '0';
        }
        
        if(ones == 0)   return s;
        
        s[n - 1] = '1';
        --ones;
        
        int i = 0;
        
        while(ones--){
            s[i++] = '1';
        }
        
        return s;
    }
};