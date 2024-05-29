class Solution {
    public void divideBy2(StringBuilder num){
        num.setLength(num.length() - 1);
    }
    
    public static void add1(StringBuilder binary) {
        int carry = 1;
        int i = binary.length() - 1;

        while (i >= 0) {
            char bit = binary.charAt(i);
            if (bit == '1' && carry == 1) {
                binary.setCharAt(i, '0');
                carry = 1;
            } else if (bit == '0' && carry == 1) {
                binary.setCharAt(i, '1');
                carry = 0;
                break;
            } else {
                break;
            }
            i--;
        }

        if (carry == 1) {
            binary.insert(0, '1');
        }
    }
    
    public int numSteps(String s) {
        StringBuilder num = new StringBuilder(s);
        int steps = 0;
        
        while(true){
            
            boolean isEqual = num.toString().equals("1");
            
            if(isEqual)     
                break;
            
            if(num.charAt(num.length() - 1) == '0')
                divideBy2(num);
            
            else
                add1(num);
        
            ++steps;
        }
        
        return steps;
    }
}