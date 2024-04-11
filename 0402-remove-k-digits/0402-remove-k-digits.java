class Solution {
    public String removeKdigits(String num, int k) {
        int n = num.length();
        
        if(n == k)  return "0";
        
        Deque<Character> st = new ArrayDeque<>();
        st.push(num.charAt(0));
        
        int i = 1;
        
        while(i < n){
            while(!st.isEmpty() && k != 0 && st.peek() > num.charAt(i)){
                st.pop();
                --k;
            }
            
            st.push(num.charAt(i++));
        }
        
        StringBuilder res = new StringBuilder();
        
        while(!st.isEmpty()){
            res.append(st.peek());
            st.pop();
        }
        
        while(res.length() != 0 && res.charAt(res.length() - 1) == '0'){
            res.setLength(res.length() - 1);
        }
        
        res.reverse();
        
        if(res.length() == 0 || k >= res.length())   return "0";
        
        if(k != 0)  res.setLength(res.length() - k);
        
        return res.toString();
    }
}