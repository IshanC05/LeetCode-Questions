class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        for(int i = 1; i <= mainTank; i++){
            if(i % 5 == 0 && additionalTank != 0){
                ++mainTank;
                --additionalTank;
            }
            ++ans;
        }
        return ans*10;
    }
};