class Solution {
public:
    int partitionString(string s) {
        
        int n = s.size(), count = 1;
        
        unordered_set<char>charSet;
        
        for(int i = 0; i < n; i++){
            
            if(charSet.find(s[i]) == charSet.end()){
                
                charSet.insert(s[i]);
                
            }else{
                
                ++count;
                
                charSet.clear();
                
                charSet.insert(s[i]);
                
            }
            
        }
        
        return count;
        
    }
};