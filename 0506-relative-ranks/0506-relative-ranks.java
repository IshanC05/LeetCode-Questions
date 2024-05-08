class Solution {
    public String[] findRelativeRanks(int[] score) {
        Comparator<Pair> pairComparator = Comparator.comparingInt(pair -> pair.first);

        PriorityQueue<Pair> pq = new PriorityQueue<>(pairComparator.reversed());
        
        for(int i = 0; i < score.length; i++){
            pq.offer(new Pair(score[i], i));
        }
        
        String[] res = new String[score.length];
        
        int i = 1;
        
        while(!pq.isEmpty()){
            Pair pair = pq.poll();
            
            if(i == 1)
                res[pair.second] = "Gold Medal";
            
            else if(i == 2)
                res[pair.second] = "Silver Medal";
            
            else if(i == 3)
                res[pair.second] = "Bronze Medal";
            
            else
                res[pair.second] = String.valueOf(i);
            
            ++i;
        }
        
        return res;
    }
}

class Pair{
    int first;
    int second;
    
    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}