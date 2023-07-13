class Solution {
public:
    
    int helper(string s, char a, int k){
        
        int count = 0, n = s.size(), i = 0, j = 0, ans = 0;
        
        while(j < n){
            
            if(s[j] != a)   ++count;
            
            while(count > k){
                
                if(s[i] != a)   --count;
                
                ++i;
                
            }
            
            ans = max(ans, j - i + 1);
            
            ++j;
            
        }
        
        return ans;
        
    }
    
    int characterReplacement(string s, int k) {
        
        vector<int>freq(26, 0);
        
        for(char i : s) ++freq[i - 'A'];
        
        int ans = 0;
        
        for(int i = 0; i < 26; i++){
            
            if(freq[i] != 0){
                
                char d = (char)(i + 'A');
                
                int currAns = helper(s, d, k);
                
                ans = max(currAns, ans);
                
            }
            
        }
        
        return ans;
        
    }
};