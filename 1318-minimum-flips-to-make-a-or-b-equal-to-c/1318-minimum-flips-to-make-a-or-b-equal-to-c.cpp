class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while (a || b || c) {
            int c_a = a % 2, c_b = b % 2, c_c = c % 2;
            if (c_c == 1 && (c_a == 0 && c_b == 0)) {
                ++count;
            } else if (c_c == 0) {
                count += (c_a + c_b);
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return count;
    }
};