class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int i = 0, j = 0, m = word1.size(), n = word2.size();
        
        int l = 0, r = 0;
        
        while(i < m && j < n){
            
            while(l < word1[i].size() && r < word2[j].size()){
                
                if(word1[i][l] != word2[j][r])  return false;
                
                ++l;
                
                ++r;
                
            }
            
            if(l == word1[i].size()){
                ++i;
                l = 0;
            }
            
            if(r == word2[j].size()){
                ++j;
                r = 0;
            }
            
        }
        
        return (i == m && j == n);
        
    }
};