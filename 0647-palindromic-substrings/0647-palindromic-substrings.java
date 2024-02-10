class Solution {
    public int countSubstrings(String s) {
        int res = 0, n = s.length();
        
        boolean[][] t = new boolean[n + 1][n + 1];
        
        for(int gap = 0; gap < n; gap++){
            for(int l = 0, r = gap; r < n; l++, r++){
                if(gap == 0){
                    t[l][r] = true;
                }else if(gap == 1){
                    t[l][r] = (s.charAt(l) == s.charAt(r));
                }else{
                    t[l][r] = (t[l + 1][r - 1] == true && s.charAt(l) == s.charAt(r));
                }
                
                if(t[l][r])     ++res;
            }    
        }
        
        return res;
    }
}