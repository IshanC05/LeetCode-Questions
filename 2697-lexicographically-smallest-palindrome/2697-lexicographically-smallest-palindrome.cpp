class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size(), res = 0;
        for(int i = 0; i < n / 2; i++){
            if(s[i] != s[n - i - 1]){
                if(s[i] < s[n - i - 1]){
                    s[n - i - 1] = s[i];
                }else{
                    s[i] = s[n - i - 1]; 
                }
                ++res;
            }
        }
        return s;
    }
};