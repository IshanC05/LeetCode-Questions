class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        Deque<Integer> dq = new ArrayDeque<>();
        
        Arrays.sort(deck);
        int i = deck.length - 1;
        
        dq.offerLast(deck[i--]);
        
        while(i >= 0){
            dq.offerFirst(dq.pollLast());
            dq.offerFirst(deck[i--]);
        }
        
        i = 0;
        
        while(!dq.isEmpty()){
            deck[i++] = dq.pollFirst();
        }
        
        return deck;
    }
}