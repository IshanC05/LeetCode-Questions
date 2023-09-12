class Solution {
public:
    int n;
    vector<int>t;
    unordered_set<string>st;
    
    int solve(int idx, string s){
        
        if(idx >= n)    return 0;
        
        if(t[idx] != -1)    return t[idx];
        
        int minExtra = n;
        
        string currStr = "";
        
        for(int i = idx; i < n; i++){
            
            currStr.push_back(s[i]);
            
            int currExtra = (st.find(currStr) == st.end()) ? currStr.size() : 0;
            
            int nextExtra = solve(i + 1, s);
            
            int totalExtra = currExtra + nextExtra;
            
            minExtra = min(minExtra, totalExtra);
            
        }
        
        return t[idx] = minExtra;
        
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        
        n = s.size();
        
        vector<int>temp(51, -1);
        
        t = temp;
        
        for(string &word : dictionary){
            st.insert(word);
        }
        
        return solve(0, s);
    }
};