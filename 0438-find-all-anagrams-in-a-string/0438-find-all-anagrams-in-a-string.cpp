class Solution {
public:
    bool isEqual(vector<int>&freqS, vector<int>&freqP){
        for(int i = 0; i < 26; i++)     if(freqS[i] != freqP[i])    return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        
        vector<int>freqS(26, 0), freqP(26, 0);
        
        for(char i : p)
            ++freqP[i - 'a'];
        
        vector<int>res;
        
        int i = 0, j = 0;
        
        while(j < s.size()){
            
            ++freqS[s[j] - 'a'];
            
            while(j - i + 1 > k){
                --freqS[s[i++] - 'a'];
            }
            
            if(j - i + 1 == k && isEqual(freqS, freqP))     res.push_back(i);
            
            ++j;
        }
        
        return res;
    }
};