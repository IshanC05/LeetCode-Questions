class Solution {
public:
    int balancedStringSplit(string s) {
        int l = 0, r = 0, ans = 0;
        for(char x : s){
            if(x == 'L'){
                ++l;
            }else{
                ++r;
            }
            ans = (l == r) ? ++ans : ans; 
        }
        return ans;
    }
};