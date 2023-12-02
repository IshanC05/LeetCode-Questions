class Solution {
public:
    bool isGood(string &s, vector<int>&freq){
    
        vector<int>sFreq(26, 0);
        
        for(char i : s)
            ++sFreq[i - 'a'];
        
        for(int i = 0; i < 26; i++){
            
            if(sFreq[i] != 0 && sFreq[i] > freq[i])     return false;
            
        }
        
        return true;
    }
    
    int countCharacters(vector<string>& words, string chars) {
        
        int res = 0;
        
        vector<int>charsFreq(26, 0);
        
        for(char i : chars)
            ++charsFreq[i - 'a'];
        
        for(string s : words){
            
            if(isGood(s, charsFreq))    res += s.size();
            
        }
        
        return res;        
    }
};