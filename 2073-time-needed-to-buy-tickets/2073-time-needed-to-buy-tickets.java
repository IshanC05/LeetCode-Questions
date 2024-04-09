class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int n = tickets.length;
        int[] res = new int[n];
        
        Queue<Pair> q = new ArrayDeque<>();
        
        for(int i = 0; i < n; i++){
            q.offer(new Pair(tickets[i], i));
        }
        
        int time = 0;
        
        while(res[k] == 0){
            int qSize = q.size();
            
            for(int i = 0; i < qSize; i++){
                Pair p = q.poll();
                
                --p.first;
                
                ++time;
                
                if(p.first == 0){
                    res[p.second] = time;
                }else{
                    q.offer(p);
                }
            }
            
        }
        
        return res[k];
    }
}

class Pair{
    int first;
    int second;
    
    Pair(int first, int second){
        this.first = first;
        this.second = second;
    }
}