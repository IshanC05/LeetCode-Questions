class Solution {
    public int maxDepth(String s) {
        int res = 0, cur = 0;

        Stack<Character> st = new Stack<>();

        for (char i : s.toCharArray()) {
            if (i == '(') {
                st.push('(');
                ++cur;
                res = Math.max(res, cur);
            } else if (i == ')') {
                st.pop();
                --cur;
            }
        }

        return Math.max(res, cur);
    }
}