class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int sumS = 0, sumT = 0;
        
        for(int i = 0; i < s.size(); i++)
            sumS += s[i];
        
        for(int i = 0; i < t.size(); i++)
            sumT += t[i];
        
        return (char)(sumT - sumS);
        
    }
};