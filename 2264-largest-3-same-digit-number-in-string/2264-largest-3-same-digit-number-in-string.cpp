class Solution {
public:   
    string largestGoodInteger(string num) {
        
        string res = "";
        
        int n = num.size();
        
        for(int i = 1; i < n - 1; i++){
            
            char a = num[i - 1], b = num[i], c = num[i + 1];
            
            if(a == b && b == c){
                
                if(res.size() == 0)     res = {a, b, c};
                
                else{
                    
                    int prev = stoi(res);
                    
                    int cur = (a - '0') * 100 + (b - '0') * 10 + (c - '0');
                    
                    if(prev < cur)  res = {a, b, c};
                    
                }
                
            }
            
        }
        
        return res;
        
    }
};