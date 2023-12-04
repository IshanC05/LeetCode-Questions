class Solution {
public:
    bool isValid(string s){
        return (s[0] == s[1] && s[1] == s[2]);
    }
    
    string largestGoodInteger(string num) {
        
        string res = "";
        
        int n = num.size();
        
        for(int i = 0; i <= n - 3; i++){
            
            string s = num.substr(i, 3);
            
            if(isValid(s)){
                
                if(res.size() == 0)     res = s;
                
                else{
                    
                    int prev = stoi(res);
                    
                    int curr = stoi(s);
                    
                    if(prev < curr)     res = to_string(curr);
                    
                }
                
            }
            
        }
        
        return res;
        
    }
};