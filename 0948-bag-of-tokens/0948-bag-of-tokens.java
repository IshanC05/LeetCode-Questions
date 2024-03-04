class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        int tempScore = 0, n = tokens.length, res = 0;
        
        Arrays.sort(tokens);
        
        int i = 0, j = n - 1;
        
        while(i <= j){
            
            if(power >= tokens[i]){
                ++tempScore;
                power -= tokens[i];
                ++i;
            }else if(tempScore >= 1){
                --tempScore;
                power += tokens[j];
                --j;
            }else{
                break;
            }
            
            res = Math.max(res, tempScore);
        }
        
        return res;
    }
}