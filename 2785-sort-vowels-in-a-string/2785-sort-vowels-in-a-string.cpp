class Solution {
public:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    
    string sortVowels(string s) {
    
        vector<int>freq(128, 0);
        
        for(int i = 0; i < s.size(); i++){
            
            if(isVowel(s[i]))   ++freq[s[i]];
            
        }
        
        int j = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            if(isVowel(s[i])){
                
                while(j < 128 && freq[j] == 0)    ++j;
                
                if(freq[j]){
                    
                    s[i] = (char)(j);
                    
                    --freq[j];
                    
                }
                
            }
            
        }
        
        
        return s;
        
    }
};