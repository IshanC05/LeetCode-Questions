class Solution {
public:
    
    void permute(string &s){
        
        int n = s.size(), i , j = n - 2;
        
        if(n == 1)  return;
        
        for(; j >= 0; j--){
            
            if(s[j] < s[j + 1]) break;
            
        }
        
        if(j < 0)   reverse(s.begin(), s.end());
        
        else{
            
            for(i = n - 1; i >= 0; i--){
                
                if(s[i] > s[j]){
                    
                    swap(s[j], s[i]);
                    
                    break;
                    
                }
                
            }
            
            reverse(s.begin() + j + 1, s.end());
            
        }
        
    }
    
    string getPermutation(int n, int k) {
        
        string s = "";
        
        for(int i = 0; i < n; i++)  
            
            s.push_back((i + 1) + '0');
        
        while(--k){
            
            permute(s);
            
        }
        
        return s;
        
    }
};