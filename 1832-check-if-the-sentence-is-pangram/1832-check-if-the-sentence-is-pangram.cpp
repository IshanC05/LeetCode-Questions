class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        vector<bool>freq(26, false);
        
        for(char i : sentence)  freq[i - 'a'] = true;
        
        for(bool i : freq)  if(!i)  return i;
        
        return true;
        
    }
};