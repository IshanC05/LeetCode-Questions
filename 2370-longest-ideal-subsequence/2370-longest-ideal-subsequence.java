class Solution {
    int[][] t;
    
    public int helper(int idx, String s, int k, int lastAscii){
        if(idx == s.length())
            return 0;

        if(t[idx][lastAscii] != -1)
            return t[idx][lastAscii];
        
        int res = helper(idx + 1, s, k, lastAscii);
        
        int currAscii = s.charAt(idx) - 'a';
        
        if(lastAscii == 26 || Math.abs(lastAscii - currAscii) <= k)
            res = Math.max(res, 1 + helper(idx + 1, s, k, currAscii));
        
        return t[idx][lastAscii] = res;
    }
    
    public int longestIdealString(String s, int k) {
        int n = s.length();
        t = new int[n + 1][27];
        
        for(int i = 0; i <= n; i++)
            Arrays.fill(t[i], -1);
        
        return helper(0, s, k, 26);
    }
}