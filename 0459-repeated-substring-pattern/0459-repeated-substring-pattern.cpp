class Solution {
public:
    
    bool helper(string subString, string originalString){
        
        string temp = "";
        
        while(temp.size() < originalString.size()){
            
            temp += subString;
            
        }
        
        return temp == originalString;
        
    }
    
    bool repeatedSubstringPattern(string s) {
       
        int n = s.size();
        
        string s1 = "";
        
        for(int i = 0; i < n / 2; i++){
            
            s1 += s[i];
            
            if(helper(s1, s))   return true;
            
        }
                
        return false;
        
    }
};