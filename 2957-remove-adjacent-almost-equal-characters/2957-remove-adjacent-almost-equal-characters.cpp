class Solution {
public:
    int t[101];
    int helper(string&word, int i, int n){
        
        if(i == n - 1 || i >= n)  return 0;
        
        else if(i == n - 2)     return (abs(word[i] - word[i + 1]) <= 1) ? 1 : 0;
        
        if(t[i] != -1)  return t[i];
        
        // change is required        
        if(abs(word[i] - word[i + 1]) <= 1){
            return t[i] = 1 + helper(word, i + 2, n);
        }
              
        return t[i] = helper(word, i + 1, n);
        
    }
    int removeAlmostEqualCharacters(string word) {
        
        memset(t, -1, sizeof(t));
        
        int n = word.size();
        
        return helper(word, 0, n);
        
    }
};