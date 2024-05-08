class Solution {
    public String[] findRelativeRanks(int[] score) {
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>((a, b) -> b.getKey() - a.getKey());
        
        for(int i = 0; i < score.length; i++){
            pq.offer(new Pair<>(score[i], i));
        }
        
        String[] res = new String[score.length];
        
        int i = 1;
        
        while(!pq.isEmpty()){
            Pair<Integer, Integer> pair = pq.poll();
            
            int idx = pair.getValue();
            
            if(i == 1)
                res[idx] = "Gold Medal";
            
            else if(i == 2)
                res[idx] = "Silver Medal";
            
            else if(i == 3)
                res[idx] = "Bronze Medal";
            
            else
                res[idx] = String.valueOf(i);
            
            ++i;
        }
        
        return res;
    }
}