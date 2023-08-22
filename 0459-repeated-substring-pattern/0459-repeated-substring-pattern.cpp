class Solution {
public:
    bool repeatedSubstringPattern(string s) {
     
        string temp = s + s;
        
        return temp.substr(1, s.size() * 2 - 2).find(s) != -1;
        
    }
};