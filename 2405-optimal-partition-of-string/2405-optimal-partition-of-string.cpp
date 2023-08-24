class Solution {
public:
    int partitionString(string s) {
        
        int n = s.size(), count = 1;
        
        vector<bool>freq(26, false);
        
        for(int i = 0; i < n; i++){
            
            int ascii = s[i] - 'a';
            
            if(!freq[ascii])    freq[ascii] = true;
            
            else{
                
                ++count;
                
                for(int i = 0; i < 26; i++)     freq[i] = false;
                
                freq[ascii] = true;
                
            }
            
        }
        
        return count;
        
    }
};