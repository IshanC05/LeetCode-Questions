class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        
        int i = 0, j = 0, k = 0;
        
        int m = s1.size(), n = s2.size(), o = s3.size();
        
        while(i < m && j < n && k < o){
            
            if(s1[i] == s2[j] && s2[j] == s3[k]){
                
                ++i;
                ++j;
                ++k;
                
            }
            
            else    break;
            
        }
        
        int removed = (m - i) + (n - j) + (o - k);
        
        int totalLength = m + n + o;
        
        return removed == totalLength ? -1 : removed;
        
    }
};