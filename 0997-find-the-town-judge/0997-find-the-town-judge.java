class Solution {
    public int findJudge(int n, int[][] trust) {
        int[] inDegree = new int[n + 1];
        int[] outDegree = new int[n + 1];
        
        for(int[] t : trust){
            int a = t[0], b = t[1];
            ++inDegree[b];
            ++outDegree[a];
        }
        
        for(int i = 1; i <= n; i++){
            if(inDegree[i] == n - 1 && outDegree[i] == 0)  return i;
        }
        
        return -1;
    }
}