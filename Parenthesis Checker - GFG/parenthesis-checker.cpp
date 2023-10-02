//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        stack<char>st;
        int i = 0, n = s.size();
        
        while(i < n){
            
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                st.push(s[i++]);
            }else{
                if(s[i] == '}'){
                    if(!st.empty() && st.top() == '{')  st.pop();
                    else    return false;
                }else if(s[i] == ']'){
                    if(!st.empty() && st.top() == '[')  st.pop();
                    else    return false;
                }else if(s[i] == ')'){
                    if(!st.empty() && st.top() == '(')  st.pop();
                    else    return false;
                }
                ++i;
            }
        }
        
        return st.size() == 0;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends