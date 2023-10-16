//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        int ans = 0;
        
        stack<char>st;
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                st.push(s[i]);
            }
            
            else if(s[i] == ')'){
                
                if(!st.empty() && st.top() == '(')  return 1;
                
                while(!st.empty() && st.top() != '(')
                    st.pop();
                    
                st.pop();
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends