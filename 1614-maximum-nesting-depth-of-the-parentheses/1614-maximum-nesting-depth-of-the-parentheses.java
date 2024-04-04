class Solution {
    public int maxDepth(String s) {
        int res = 0, brackets = 0;

        for (char i : s.toCharArray()) {
            if (i == '(') {
                ++brackets;
            } else if (i == ')') {
                --brackets;
            }
            
            res = Math.max(res, brackets);
        }

        return res;
    }
}