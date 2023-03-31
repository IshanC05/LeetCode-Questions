class Solution {
public:
    int reverse(int x) {
        long long ans = 0, temp_x=x;
        int negative = (x > 0 ? 0 : 1);
        while(temp_x){
            int rem = temp_x % 10;
            ans = ans*10 + rem;
            temp_x = temp_x/10;
        }
        if(ans >= INT_MIN and ans <= INT_MAX){
            return ans;
        }
        return 0;
    }
};