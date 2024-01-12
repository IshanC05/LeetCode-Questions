class Solution {
public:
    bool isVowel(char a){
        a = tolower(a);
        return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
    }
    bool halvesAreAlike(string s) {
        int a = 0, b = 0, n = s.length();
        
        for(int i = 0; i < n; i++){
            if(isVowel(s[i])){
                
                if(i < n / 2)     ++a;
                
                else    ++b;
            }
        }
        
        return a == b;
    }
};