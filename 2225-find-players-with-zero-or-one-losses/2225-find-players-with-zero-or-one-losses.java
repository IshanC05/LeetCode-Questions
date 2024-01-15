class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        Map<Integer, Integer> players = new TreeMap<>();

        for (int[] match : matches) {
            players.put(match[1], players.getOrDefault(match[1], 0) + 1);
        }

        for (int[] match : matches) {
            if (!players.containsKey(match[0])) {
                players.put(match[0], 0);
            }
        }

        List<Integer> win = new ArrayList<>();
        List<Integer> lose = new ArrayList<>();

        for (Map.Entry<Integer, Integer> entry : players.entrySet()) {
            if (entry.getValue() == 0) {
                win.add(entry.getKey());
            }

            if (entry.getValue() == 1) {
                lose.add(entry.getKey());
            }
        }

        List<List<Integer>> result = new ArrayList<>();
        result.add(win);
        result.add(lose);

        return result;
    }
}