class Solution {
    public int pivotInteger(int n) {
        int sum1 = 0, sum2 = (n * (n + 1)) / 2;
        
        for(int i = 1; i <= n; i++){
            sum1 += i;
            sum2 -= i;
            
            if(sum1 == sum2 + i)    return i;
        }
        
        return -1;
    }
}