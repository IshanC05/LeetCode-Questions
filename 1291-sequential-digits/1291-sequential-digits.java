class Solution {
    public static List<Integer> sequentialDigits(int low, int high) {
        String start = String.valueOf(low), end = String.valueOf(high);
        String digits = "123456789";

        List<Integer> res = new ArrayList<>();
        Set<Integer> st = new TreeSet<>();

        for (int len = start.length(); len <= end.length(); len++) {
            for (int i = 0; i <= digits.length() - len; i++) {
                String temp = digits.substring(i, i + len);
                st.add(Integer.parseInt(temp));
            }
        }

        for (Integer i : st) {
            if (i >= low && i <= high) {
                res.add(i);
            }
        }

        return res;
    }
}