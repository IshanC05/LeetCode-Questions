class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        unordered_set<char>charSet;
        
        for(char i : sentence)  charSet.insert(i);
        
        return charSet.size() == 26;
        
    }
};