class Solution {
    public int tribonacci(int n) {
        int t0 = 0, t1 = 1, t2 = 1;
        int res = 0;
        
        if(n < 3)
            return (n == 0 ? 0 : 1);
        
        for(int i = 3; i <= n; i++){
            res = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = res;
        }
        
        return res;
    }
}