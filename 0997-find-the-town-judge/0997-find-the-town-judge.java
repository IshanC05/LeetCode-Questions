class Solution {
    public int findJudge(int n, int[][] trust) {
        int[] trustCount = new int[n + 1];
        boolean[] trustSomeone = new boolean[n + 1];
        
        for(int[] t : trust){
            int a = t[0], b = t[1];
            ++trustCount[b];
            trustSomeone[a] = true;
        }
        
        for(int i = 1; i <= n; i++){
            if(trustCount[i] == n - 1 && trustSomeone[i] == false)  return i;
        }
        
        return -1;
    }
}