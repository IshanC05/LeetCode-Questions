class Solution {
public:
    long long minimumCost(string s) {
        long long ans = 0, n = s.size();
        for(int i = 1; i < n; i++){
            if(s[i] != s[i - 1]){
                if(i < n - i){
                    ans += i;
                }else{
                    ans += n - i;
                }
            }
        }
        return ans;
    }
};