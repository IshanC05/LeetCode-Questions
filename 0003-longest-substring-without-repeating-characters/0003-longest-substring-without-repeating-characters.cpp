class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size(), i = 0, j = 0, ans = 0;
        
        unordered_set<char>charSet;
        
        while(j < n){
            
            if(charSet.find(s[j]) == charSet.end()){
                
                charSet.insert(s[j++]);
                
                int size = charSet.size();
                
                ans = max(ans, size);
                
            }else{
                
                while(charSet.find(s[j]) != charSet.end()){
                    
                    charSet.erase(s[i++]);
                    
                }
                
            }
        }
        
        return ans;
    }
};