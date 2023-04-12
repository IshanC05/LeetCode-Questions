class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,n=s.size(), ans= 0, size;
        unordered_set<char>charSet;
        while(j < n){
            if(!charSet.count(s[j])){
                charSet.insert(s[j++]);
                size = charSet.size();
                ans = max(ans, size);
            }else{
                charSet.erase(s[i++]);
            }
        }
        return ans;
    }
};