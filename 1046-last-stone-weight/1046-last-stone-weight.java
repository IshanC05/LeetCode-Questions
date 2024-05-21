class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        for(int stone : stones)
            pq.offer(stone);
        
        while(pq.size() >= 2){
            int x = pq.poll();
            int y = pq.poll();
            
            if(x == y)
                continue;
            else
                pq.offer(Math.abs(x - y));
        }
        
        if(pq.size() == 1)
            return pq.poll();
        
        return 0;
    }
}