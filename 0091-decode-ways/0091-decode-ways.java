public class Solution {

    private int[] t;

    public int numDecodings(String s) {
        int n = s.length();
        t = new int[101];
        Arrays.fill(t, -1);
        return helper(s, 0, n);
    }

    private int helper(String s, int i, int n) {
        if(i == n)  return 1;
        else if(i == n - 1) return s.charAt(i) == '0' ? 0 : 1;
        else if (s.charAt(i) == '0') return 0;

        if (t[i] != -1) return t[i];

        int res = helper(s, i + 1, n);

        if (i + 1 < n) {
            int num = Integer.parseInt(s.substring(i, i + 2));
            if (num <= 26) res += helper(s, i + 2, n);
        }

        return t[i] = res;
    }
}