class Solution {
    private int t[][];
    int helper(String s1, String s2, int m, int n){
        if(m == 0 || n == 0)    return 0;
        
        if(t[m][n] != -1)   return t[m][n];
        
        if(s1.charAt(m - 1) == s2.charAt(n - 1))
            return t[m][n] = 1 + helper(s1, s2, m - 1, n - 1);
        
        int a = helper(s1, s2, m - 1, n);
        int b = helper(s1, s2, m, n - 1);
        
        return t[m][n] = Math.max(a, b);
    }
    public int longestCommonSubsequence(String text1, String text2) {
        t = new int[1001][1001];
        
        for(int i = 0; i < 1001; i++){
            Arrays.fill(t[i], -1);
        }
        int m = text1.length(), n = text2.length();
        return helper(text1, text2, m, n);
    }
}