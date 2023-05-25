class Solution {
public:
    bool isValid(string s){
        int n = s.size();
        if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u'){
            if(s[n-1] == 'a' || s[n-1] == 'e' || s[n-1] == 'i' || s[n-1] == 'o' || s[n-1] == 'u'){
                return true;
            }
        }
        return false;
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), curr = 0;
        vector<int>prefixArray(n, 0);
        for(int i = 0; i < n; i++){
            string temp = words[i];
            curr = (isValid(temp)) ? ++curr : curr;
            prefixArray[i] = curr;
        }
        vector<int>ans;
        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            
            if(l == 0){
                ans.push_back(prefixArray[r]);
            }else{
                ans.push_back(prefixArray[r] - prefixArray[l - 1]);
            }
        }
        return ans;
    }
};