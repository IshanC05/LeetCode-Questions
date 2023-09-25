class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int xorVal = 0;
        
        for(int i = 0; i < s.size(); i++)
            xorVal = (xorVal ^ s[i]);
        
        for(int i = 0; i < t.size(); i++)
            xorVal = (xorVal ^ t[i]);
        
        return (char)(xorVal);
        
    }
};