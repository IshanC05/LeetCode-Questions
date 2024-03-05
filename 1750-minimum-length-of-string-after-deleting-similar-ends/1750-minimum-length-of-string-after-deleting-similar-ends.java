class Solution {
    int helper(String s, int l, int r){
        if(l > r)  return 0;
        if(l == r)  return 1;
        if(s.charAt(l) != s.charAt(r))  return (r - l + 1);
        
        char c = s.charAt(l);
        
        while(l <= r && s.charAt(l) == c)    ++l;
        while(r >= l && s.charAt(r) == c)    --r;
        
        return helper(s, l, r);        
    }
    public int minimumLength(String s) {
        int n = s.length();
        int i = 0, j = n - 1;
        return helper(s, i, j);
    }
}