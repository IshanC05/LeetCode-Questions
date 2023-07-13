class Solution {
public:
    
    int characterReplacement(string s, int k) {
        
        vector<int>freq(26, 0);
        
        int i = 0, n = s.size(), maxFreq = 0, ans = 0;
        
        for(int j = 0; j < n; j++){
            
            ++freq[s[j] - 'A'];
            
            maxFreq = max(maxFreq, freq[s[j] - 'A']);
            
            bool valid = j - i + 1 - maxFreq <= k;
            
            if(!valid){
                
                --freq[s[i] - 'A'];
                
                ++i;
                
            }
            
            ans = max(ans, j - i + 1);
            
        }
        
        return ans;
        
    }
};