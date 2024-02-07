class Solution {
    public String frequencySort(String s) {
        int[] freq = new int[128];
        
        for (char c : s.toCharArray()) {
            freq[c]++;
        }
        
        PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair p2) {
                return Integer.compare(p2.freq, p1.freq);
            }
        });
        
        for (int i = 0; i < 128; i++) {
            if (freq[i] != 0) {
                pq.add(new Pair(freq[i], (char)i));
            }
        }
        
        StringBuilder res = new StringBuilder();
        
        while (!pq.isEmpty()) {
            Pair top = pq.poll();
            res.append(Character.toString(top.c).repeat(top.freq));
        }
        
        return res.toString();
    }
    
    class Pair {
        int freq;
        char c;
        
        Pair(int freq, char c) {
            this.freq = freq;
            this.c = c;
        }
    }
}