class Solution {
    public int[] dailyTemperatures(int[] temp) {
        int n = temp.length;
        int[] res = new int[n];
        
        Deque<Integer>st = new ArrayDeque<>();
        st.push(n - 1);
        
        for(int i = n - 2; i >= 0; i--){
            
            while(!st.isEmpty() && temp[st.peek()] <= temp[i])
                st.pop();
            
            res[i] = (st.isEmpty() ? 0 : st.peek() - i);
            
            st.push(i);            
        }
        
        return res;
    }
}