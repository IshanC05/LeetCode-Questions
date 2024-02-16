class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        
        for (int i : arr)
            map.put(i, map.getOrDefault(i, 0) + 1);
        
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>(
            (a, b) -> a.getValue() - b.getValue()
        );
        
        for (Map.Entry<Integer, Integer> entry : map.entrySet())
            pq.offer(entry);
        
        while (k > 0 && !pq.isEmpty()) {
            Map.Entry<Integer, Integer> top = pq.peek();
            if (k >= top.getValue()) {
                k -= top.getValue();
                pq.poll();
            } else {
                break;
            }
        }
        
        return pq.size();    
    }
}