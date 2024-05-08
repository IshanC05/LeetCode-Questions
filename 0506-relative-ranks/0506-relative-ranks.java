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
            
            if(i == 1)
                res[pair.getValue()] = "Gold Medal";
            
            else if(i == 2)
                res[pair.getValue()] = "Silver Medal";
            
            else if(i == 3)
                res[pair.getValue()] = "Bronze Medal";
            
            else
                res[pair.getValue()] = String.valueOf(i);
            
            ++i;
        }
        
        return res;
    }
}