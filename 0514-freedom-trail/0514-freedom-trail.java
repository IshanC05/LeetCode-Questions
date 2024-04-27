class Solution {
    int n, m;
    int[][] t;
    
    public int helper(String ring, String key, int i, int j) {
        if (i == n)
            return 0;
        
        if(t[i][j] != -1)
            return t[i][j];

        char currChar = ring.charAt(j);
        char reqChar = key.charAt(i);

        if (currChar == reqChar)
            return 1 + helper(ring, key, i + 1, j);

        int minStepsLeft = 0, minStepsRight = 0;

        int l = j;
        int r = j;

        while (ring.charAt(l) != reqChar) {
            --l;
            ++minStepsLeft;
            if (l < 0) l = m - 1;
        }

        while (ring.charAt(r) != reqChar) {
            ++r;
            ++minStepsRight;
            if (r == m) r = 0;
        }

        int resA = minStepsLeft + helper(ring, key, i + 1, l);
        int resB = minStepsRight + helper(ring, key, i + 1, r);

        return t[i][j] = 1 + Math.min(resA, resB);
    }

    public int findRotateSteps(String ring, String key) {
        n = key.length();
        m = ring.length();
        
        t = new int[n + 1][m + 1];
        
        for(int i = 0; i < n; i++)
            Arrays.fill(t[i], -1);
        
        return helper(ring, key, 0, 0);
    }
}
