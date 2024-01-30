class Solution {
    public boolean isOperator(String s) {
        return (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/"));
    }

    public String helper(String a, String b, String op) {
        int x = Integer.parseInt(a);
        int y = Integer.parseInt(b);

        int res = 0;

        if (op.equals("+")) res = x + y;
        if (op.equals("-")) res = x - y;
        if (op.equals("*")) res = x * y;
        if (op.equals("/")) res = x / y;

        return Integer.toString(res);
    }

    public int evalRPN(String[] tokens) {
        Stack<String> st = new Stack<>();

        for (int i = 0; i < tokens.length; i++) {
            if (!isOperator(tokens[i])) {
                st.push(tokens[i]);
            } else {
                String s1 = st.pop();
                String s2 = st.pop();

                String res = helper(s2, s1, tokens[i]);
                st.push(res);
            }
        }

        return Integer.parseInt(st.pop());
    }
}