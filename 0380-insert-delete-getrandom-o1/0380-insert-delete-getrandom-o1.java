class RandomizedSet {
    Set<Integer>st;
    public RandomizedSet() {
        st = new HashSet<>();
    }
    
    public boolean insert(int val) {
        return st.add(val);
    }
    
    public boolean remove(int val) {
        return st.remove(val);
    }
    
    public int getRandom() {
        int sz = st.size();        
        int idx = new Random().nextInt(sz);
        
        Iterator<Integer>it = st.iterator();
        
        for(int i = 0; i < idx; i++){
            it.next();
        }
        
        return it.next();
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */