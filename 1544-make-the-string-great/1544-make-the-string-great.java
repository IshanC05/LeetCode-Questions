class Solution {
    public boolean check(Deque<Character> stack, char b){
        char a = stack.peek();
        
        if(a >= 'A' && a <= 'Z' && b >= 'a' && b <= 'z' && Character.toLowerCase(a) == b)    return true;
        
        else if(a >= 'a' && a <= 'z' && b >= 'A' && b <= 'Z' && Character.toUpperCase(a) == b)   return true;
        
        return false;
    }
    public String makeGood(String s) {
        int n = s.length();
        Deque<Character> stack = new ArrayDeque<>();
        
        for(int i = 0; i < n;){
            while(i < n && !stack.isEmpty() && check(stack, s.charAt(i))){
                stack.pop();
                i++;
            }
            
            if(i < n)   stack.push(s.charAt(i++));
        }
        
        StringBuilder res = new StringBuilder();
        
        while(!stack.isEmpty()){
            res.append(stack.peek());
            stack.pop();
        }
        
        res.reverse();
        
        return res.toString();
    }
}