class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;
        
        int i = 0, n = s.length();
        
        while(i < n){
            if(st.empty() || st.top().first != s[i]){
                st.push({s[i++], 1});
            }else if(st.top().first == s[i]){
                int count = st.top().second;
                st.pop();
                st.push({s[i++], count + 1});
            }
            
            while(!st.empty() && st.top().second == k)
                st.pop();
        }
        
        string res = "";
        
        while(!st.empty()){
            while(st.top().second--){
                res.push_back(st.top().first);
            }
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};