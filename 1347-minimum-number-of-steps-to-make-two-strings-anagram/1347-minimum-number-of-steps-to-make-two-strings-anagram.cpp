class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>freqS(26, 0), freqT(26, 0);
        
        for(char i : s)
            ++freqS[i - 'a'];
        
        for(char i : t)
            ++freqT[i - 'a'];
        
        int res = 0;
        
        for(int i = 0; i < 26; i++){
            res += abs(freqS[i] - freqT[i]);
        }
        
        return res / 2;            
    }
};