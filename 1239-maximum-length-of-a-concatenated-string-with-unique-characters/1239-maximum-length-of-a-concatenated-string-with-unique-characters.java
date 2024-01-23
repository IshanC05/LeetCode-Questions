class Solution {
    private int[] used = new int[26];

    private boolean isValid(String s) {
        Set<Character> set = new HashSet<>();
        for (char i : s.toCharArray()) {
            set.add(i);
        }
        return set.size() == s.length();
    }

    private boolean check(String s) {
        for (char i : s.toCharArray()) {
            if (used[i - 'a'] + 1 > 1) {
                return false;
            }
        }
        return true;
    }

    private void mark(String s, boolean val) {
        for (char i : s.toCharArray()) {
            if (val) {
                ++used[i - 'a'];
            } else {
                --used[i - 'a'];
            }
        }
    }

    private int helper(List<String> arr, int idx) {
        if (idx >= arr.size()) {
            return 0;
        }

        int take = 0, skip = 0;

        if (isValid(arr.get(idx)) && check(arr.get(idx))) {
            skip = helper(arr, idx + 1);
            mark(arr.get(idx), true);
            take = arr.get(idx).length() + helper(arr, idx + 1);
            mark(arr.get(idx), false);
        } else {
            skip = helper(arr, idx + 1);
        }

        return Math.max(take, skip);
    }

    public int maxLength(List<String> arr) {
        for (int i = 0; i < 26; i++) {
            used[i] = 0;
        }
        return helper(arr, 0);
    }
}