class Solution {
    boolean valid(int[] freqS, int[] freqT) {
        for (int i = 0; i < 128; i++) {
            if (freqT[i] > freqS[i]) {
                return false;
            }
        }
        return true;
    }
    public String minWindow(String s, String t) {
        String res = "";

        int m = s.length(), n = t.length();
        if (m < n)      return res;

        int[] freqS = new int[128];
        int[] freqT = new int[128];

        for (char x : t.toCharArray())
            ++freqT[x];

        int i = 0, j = 0, start = 0, len = Integer.MAX_VALUE;

        while (j < m) {
            ++freqS[s.charAt(j)];

            while (valid(freqS, freqT)) {
                if (j - i + 1 < len) {
                    len = j - i + 1;
                    start = i;
                }
                --freqS[s.charAt(i++)];
            }

            ++j;
        }

        if (len == Integer.MAX_VALUE)   return res;

        return s.substring(start, start + len);
    }
}