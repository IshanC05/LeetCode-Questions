class Solution {
    public String minRemoveToMakeValid(String s) {
        int n = s.length();
        boolean[] skip = new boolean[n];
        
        Deque<Pair> st = new ArrayDeque<>();
        
        for(int i = 0; i < n; i++){
            
            char c = s.charAt(i);
            
            if(c >= 'a' && c <= 'z')    
                continue;
            
            else if(c == '(')
                st.push(new Pair(c, i));
            
            else{
                
                if(st.isEmpty())    
                    skip[i] = true;
                
                else if(st.peek().first == '(')
                    st.poll();
            }
        }
        
        while(!st.isEmpty()){
            Pair p = st.poll();
            skip[p.second] = true;
        }
        
        StringBuilder res = new StringBuilder();
        
        for(int i = 0; i < n; i++){
            if(!skip[i])    res.append(s.charAt(i));
        }
        
        return res.toString();
    }
}

class Pair{
    char first;
    int second;
    
    Pair(char c, int idx){
        first = c;
        second = idx;
    }
}