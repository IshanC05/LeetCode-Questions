class Solution {
public:
    int addMinimum(string word) {
        int i=0, n=word.size(), ans = 0;
        while(i < n){
            string s1 = word.substr(i, 3);
            string s2 = word.substr(i, 2);
            if(s1 == "abc"){
                i = i + 3;
            }else if(s2 == "ab" || s2 == "ac" || s2 == "bc"){
                ++ans;
                i = i + 2;
            }else{
                ans = ans + 2;
                ++i;
            }
        }
        return ans;
    }
};