import java.util.Arrays;

class Solution {
    public int findContentChildren(int[] g, int[] s) {
        int m = g.length, n = s.length;
        
        Arrays.sort(g);
        Arrays.sort(s);
        
        int i = 0, j = 0, res = 0;
        
        while(i < m && j < n){
            
            if(g[i] <= s[j]){
                ++res;
                ++i;
            }
            
            ++j;            
        }
        
        return res;
    }
}