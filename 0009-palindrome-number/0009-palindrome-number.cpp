class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        long long num=0, temp_x=x;
        while(temp_x){
            int rem = temp_x%10;
            num = num*10 + rem;
            temp_x = temp_x/10;
        }
        return (x == num);
    }
};