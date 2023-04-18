//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    int ans = 0;
    if(s.size() == 0){
        return ans;
    }else if (s.size() % 2 == 1){
        return -1;
    }
    stack<char>st;
    for(int i=0; i<s.size(); i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else if(s[i] == '{'){
            st.push(s[i]);
        }else{
            if(s[i] == '}' and st.top() == '{'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
    }
    while(!st.empty()){
        char c1 = st.top();
        st.pop();
        char c2 = st.top();
        st.pop();
        ans = (c1 != c2) ? (ans = ans + 2) : ++ans;
    }
    return ans;
}