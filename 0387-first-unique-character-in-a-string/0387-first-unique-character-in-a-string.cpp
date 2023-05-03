class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size(), ansIdx = -1;
        char ans = ' ';
        unordered_map<char,int>m;
        for(int i = 0; i < n; i++){
            ++m[s[i]];
        }
        for(int i = 0; i < n; i++){
            if(m[s[i]] == 1){
                return s.find(s[i]);
            }
        }
        return -1;
    }
};