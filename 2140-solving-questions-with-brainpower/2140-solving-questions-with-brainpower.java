class Solution {
    public long[] t;
    public long helper(int[][] arr, int idx){
        if(idx >= arr.length)   return 0;
        
        if(t[idx] != -1)    return t[idx];
        
        long solve = arr[idx][0] + helper(arr, idx + 1 + arr[idx][1]);
        long skip = helper(arr, idx + 1);
        
        return t[idx] = Math.max(solve, skip);
    }
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        t = new long[n];
        Arrays.fill(t, -1);
        return helper(questions, 0);
    }
}