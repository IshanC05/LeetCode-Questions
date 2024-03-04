class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int tempScore = 0, n = tokens.size(), res = 0;
        
        sort(tokens.begin(), tokens.end());
        
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
            
            res = max(res, tempScore);
        }
        
        return res;
    }
};