class Solution {
public:
    bool cmp(string s1, string s2){
        return s1.size() < s2.size();
    }
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string s1 = strs[0], s2 = strs[strs.size() - 1];
        int i = 0;
        string ans = "";
        while(i < s1.size()){
            if(s1[i] == s2[i]){
                ans.push_back(s1[i]);
            }else{
                break;
            }
            ++i;
        }
        return ans;
    }
};