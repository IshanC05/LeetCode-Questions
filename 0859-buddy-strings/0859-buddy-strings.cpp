class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if(s.size() != goal.size())     return false;
        
        int count = 0;
        
        bool repeating = false;
        
        vector<int>freqS(26, 0), freqG(26, 0);
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] != goal[i])     ++count;
            
            ++freqS[s[i] - 'a'];

            ++freqG[goal[i] - 'a'];
            
            if(freqS[s[i] - 'a'] > 1)    repeating = true;
        }
        
        if(count > 2)   return false;
        
        else if(count == 0){
            
            return repeating;
        }
        
        else{
            
            for(int i = 0; i < 26; i++){
                if(freqG[i] != freqS[i])    return false;
            }
            
            return true;
        }
    }
};