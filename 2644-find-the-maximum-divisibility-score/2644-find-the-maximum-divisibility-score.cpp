class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ansElem=0, ansCount = -1;
        for(int i : divisors){
            int curCount = 0;
            for(int j : nums){
                curCount = (j % i == 0) ? ++curCount : curCount;
            }
            if(curCount >= ansCount){
                if(curCount == ansCount){
                    ansElem = min(ansElem, i);
                }else{
                    ansElem = i;
                    ansCount = curCount;
                }
            }
        }
        return ansElem;
    }
};