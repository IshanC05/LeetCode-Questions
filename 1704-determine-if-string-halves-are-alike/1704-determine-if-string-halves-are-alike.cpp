class Solution {
public:
    bool isVowel(char a){
        return (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U' || a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
    }
    bool halvesAreAlike(string s) {
        int a = 0, b = 0, n = s.length();
        
        for(int i = 0; i < n; i++){
            if(isVowel(s[i])){
                
                if(i <= (s.length() / 2) - 1)     ++a;
                
                else    ++b;
            }
        }
        
        return a == b;
    }
};