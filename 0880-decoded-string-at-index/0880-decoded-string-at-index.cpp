class Solution {
public:
  string decodeAtIndex(string s, int k) {
        long long sz = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            if(isalpha(s[i]))  ++sz;
            
            else{
                int d = s[i] - '0';
                sz = sz * d;
            }            
        }
        
        for(int i = s.size() - 1; i >= 0; --i){
            
            k = k % sz;
            
            if(k == 0 && isalpha(s[i])){
                return string(1, s[i]);
            }
            if(isalpha(s[i])){
                --sz;
            }else{
                sz = sz / (s[i] - '0');
            }
               
        }
        
        return "";
    }
};