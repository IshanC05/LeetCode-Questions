class Solution {
public:
    int n, m;
    int t[101][101];
    
    int helper(string ring, string key, int i, int j) {
        if (i == n)
            return 0;
        
        if(t[i][j] != -1)
            return t[i][j];

        char currChar = ring[j];
        char reqChar = key[i];

        if (currChar == reqChar)
            return 1 + helper(ring, key, i + 1, j);

        int minStepsLeft = 0, minStepsRight = 0;

        int l = j, r = j;

        while (ring[l] != reqChar) {
            --l;
            ++minStepsLeft;
            if (l < 0) l = m - 1;
        }

        while (ring[r] != reqChar) {
            ++r;
            ++minStepsRight;
            if (r == m) r = 0;
        }

        int resA = minStepsLeft + helper(ring, key, i + 1, l);
        int resB = minStepsRight + helper(ring, key, i + 1, r);

        return t[i][j] = 1 + min(resA, resB);
    }

    int findRotateSteps(string ring, string key) {
        n = key.size();
        m = ring.size();
        
        memset(t, -1, sizeof(t));
        
        return helper(ring, key, 0, 0);
    }
};