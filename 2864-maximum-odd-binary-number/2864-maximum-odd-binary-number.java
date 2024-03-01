class Solution {
    public String maximumOddBinaryNumber(String s) {
        int ones = 0, n = s.length();
        
        for(char i : s.toCharArray()){
            if(i == '1')    ++ones;
        }
        
        if(ones == 0)   return s;
        
        StringBuilder sb = new StringBuilder();
        
        for(int i = 0; i < n; i++){
            sb.append('0');
        }
        
        sb.setCharAt(n - 1, '1');
        --ones;
        
        int i = 0;
        
        while(ones-- > 0){
            sb.setCharAt(i, '1');
            ++i;
        }
        
        return sb.toString();
    }
}