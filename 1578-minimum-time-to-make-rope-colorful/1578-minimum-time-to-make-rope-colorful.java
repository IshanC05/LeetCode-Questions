class Solution {
    public int minCost(String c, int[] t) {
        int n = c.length();
        int res = t[0], max_cost = t[0];
        
        for(int i = 1; i < n; i++){
            if(c.charAt(i) != c.charAt(i - 1)){
                res -= max_cost;
                max_cost = 0;
            }
            res += t[i];
            max_cost = Math.max(max_cost, t[i]);
        }
        
        return res - max_cost;
    }
}