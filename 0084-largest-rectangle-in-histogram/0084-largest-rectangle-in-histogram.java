class Solution {
    public int[] prevSmaller(int[] arr, int n) {
        int[] ans = new int[n];
        Stack<Integer> st = new Stack<>();
        
        st.push(0);
        ans[0] = -1;
        
        for (int i = 1; i < n; i++) {
            while (!st.isEmpty() && arr[st.peek()] >= arr[i])
                st.pop();
                
            if (st.isEmpty())
                ans[i] = -1;
            else
                ans[i] = st.peek();
                
            st.push(i);
        }
        
        return ans;
    }
    
    public int[] nextSmaller(int[] arr, int n) {
        int[] ans = new int[n];
        Stack<Integer> st = new Stack<>();
        
        st.push(n - 1);
        ans[n - 1] = n;
        
        for (int i = n - 2; i >= 0; --i) {
            while (!st.isEmpty() && arr[st.peek()] >= arr[i])
                st.pop();
                
            if (st.isEmpty())
                ans[i] = n;
            else
                ans[i] = st.peek();
                
            st.push(i);
        }
        
        return ans;
    }
    
    public int largestRectangleArea(int[] arr) {
        int n = arr.length;
        
        int[] ps = prevSmaller(arr, n);
        int[] ns = nextSmaller(arr, n);
        
        int ans = Integer.MIN_VALUE;
        
        for (int i = 0; i < n; i++) {
            int curr = (ns[i] - ps[i] - 1) * arr[i];
            ans = Math.max(ans, curr);
        }
        
        return ans;
    }
}