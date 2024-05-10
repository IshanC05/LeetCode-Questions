class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        PriorityQueue<Double> pq = new PriorityQueue<>();
        
        Map<Double, Pair<Integer, Integer>> map = new HashMap<>();
        
        int n = arr.length;
        
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                
                double x = arr[i];
                double y = arr[j];
                double z = x / y;
                
                pq.offer(z);
                
                map.put(z, new Pair<Integer, Integer>(arr[i], arr[j]));
                
            }
        }
        
        while(--k > 0 && !pq.isEmpty()){
            pq.poll();
        }
        
        int[] res = new int[2];
        
        if(pq.isEmpty())
            return res;
        
        double key = pq.poll();
        
        Pair<Integer, Integer> pair = map.get(key);
        
        res[0] = pair.getKey();
        res[1] = pair.getValue();
        
        return res;
    }
}