class Solution {
public:
    string removeKdigits(string S, int k) {
        if(S.length() <= k)     return "0";
        
        stack<char>st;
        st.push(S[0]);
        
        for(int i = 1; i < S.length(); i++){
            while(k > 0 && !st.empty() && st.top() > S[i]){
                --k;
                st.pop();
            }
            st.push(S[i]);
        }
        
        while(k > 0 && !st.empty()){
            st.pop();
            --k;
        }
        
        S.clear();
        
        while(!st.empty()){
            S.push_back(st.top());
            st.pop();
        }
        
        while(S.length() > 0 && S.back() == '0')
            S.pop_back();
            
        reverse(S.begin(), S.end());
        
        return (S == ""  ? "0" : S);
    }
};