class Solution {
    long resultBaseNode = 0;
    int[] count;
    int N;

    public int dfsBase(Map<Integer, List<Integer>> adj, int currNode, int prevNode, int currDepth) {
        int totalNode = 1;

        resultBaseNode += currDepth;

        List<Integer> neighbors = adj.get(currNode);
        if (neighbors != null) {
            for (int child : neighbors) {
                if (child == prevNode)
                    continue;

                totalNode += dfsBase(adj, child, currNode, currDepth + 1);
            }
        }

        count[currNode] = totalNode;

        return totalNode;
    }

    public void DFS(Map<Integer, List<Integer>> adj, int parentNode, int prevNode, int[] result) {
        List<Integer> neighbors = adj.get(parentNode);
        if (neighbors != null) {
            for (int child : neighbors) {
                if (child == prevNode)
                    continue;

                result[child] = result[parentNode] - count[child] + (N - count[child]);
                DFS(adj, child, parentNode, result);
            }
        }
    }

    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        N = n;
        count = new int[n];

        for (int[] vec : edges) {
            int u = vec[0];
            int v = vec[1];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        resultBaseNode = 0;

        dfsBase(adj, 0, -1, 0);

        int[] result = new int[n];
        result[0] = (int) resultBaseNode;

        DFS(adj, 0, -1, result);

        return result;
    }
}
