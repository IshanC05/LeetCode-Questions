class Solution {
    public boolean isNStraightHand(int[] hand, int W) {
        int N = hand.length;
        if (N % W != 0) {
            return false;
        }

        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : hand) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        Arrays.sort(hand);

        for (int num : hand) {
            if (freq.get(num) > 0) {
                for (int i = 0; i < W; i++) {
                    int cur = num + i;
                    if (freq.getOrDefault(cur, 0) <= 0) {
                        return false;
                    }
                    freq.put(cur, freq.get(cur) - 1);
                }
            }
        }

        return true;
    }
}