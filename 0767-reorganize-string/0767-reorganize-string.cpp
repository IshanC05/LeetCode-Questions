class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.size(), k = 0;
        
        vector<int>freq(26, 0);
        
        int maxFreq = 0, maxChar = 0;
        
        for(char i : s) {
            
            ++freq[i - 'a'];
            
            if(freq[i - 'a'] > maxFreq){
                
                maxFreq = freq[i - 'a'];
                
                maxChar = i - 'a';
                
            }
            
        }
        
        if(maxFreq > (n + 1) / 2)   return "";
        
        freq[maxChar] = 0;
        
        while(maxFreq){
            
            if(k >= n)  k = 1;
            
            s[k] = (char)(maxChar + 'a');
            
            k += 2;
            
            --maxFreq;
        }
        
        for(int i = 0; i < 26; i++){
            
            while(freq[i]){
                
                if(k >= n)  k = 1;
                
                s[k] = (char)(i + 'a');
                
                k += 2;
                
                --freq[i];
            }
            
        }
        
        return s;
        
    }
};