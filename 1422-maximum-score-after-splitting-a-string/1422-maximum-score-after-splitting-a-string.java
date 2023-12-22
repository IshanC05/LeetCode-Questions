public class Solution {
    public int maxScore(String s) {
        int count1s = 0, count0s = 0;

        for (char i : s.toCharArray())
            if (i == '1')   ++count1s;

        int res = 0;

        for (int i = 0; i < s.length() - 1; i++) {
            
            if (s.charAt(i) == '0')     ++count0s;
            
            if (s.charAt(i) == '1')     --count1s;

            res = Math.max(res, count1s + count0s);
        }

        return res;
    }
}
