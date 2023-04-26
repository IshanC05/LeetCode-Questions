class Solution {
public:
    int reduce(int n){
        int res = 0;
        while(n){
            res = res + n % 10;
            n = n / 10;
        }
        return res;
    }
    int addDigits(int num) {
        if(num < 10){
            return num;
        }
        int res = 0;
        while(num > 9){
            res = reduce(num);
            num = res;
        }
        return res;
    }
};