//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string, int> m;
    int solve(string s, int i, int j, bool isTrue){
        if(i>j) return 0;
        if(i==j){
            if(isTrue==true){
                return s[i]=='T';
            }
            else{
                return s[i]=='F';
            }
        }
        string temp=to_string(i); temp.push_back(' ');
        temp.append(to_string(j)); temp.push_back(' ');
        temp.append(to_string(isTrue));
        if(m.find(temp)!=m.end()){
            return m[temp];
        }
        
        int ans=0;
        for(int k=i+1;k<=j-1;k=k+2){
            int lt = solve(s,i,k-1,true);
            int lf = solve(s,i,k-1,false);
            int rt = solve(s,k+1,j,true);
            int rf = solve(s,k+1,j,false);
            
            if(s[k]=='^'){
                if(isTrue==true){
                    ans = (ans+lt*rf+lf*rt)%1003;
                }
                else ans = (ans+lf*rf+lt*rt)%1003;
            }
            else if(s[k]=='&'){
                if(isTrue==true){
                    ans = (ans+lt*rt)%1003;
                }
                else ans=(ans+lt*rf+lf*rt+lf*rf)%1003;
            }
            else if(s[k]=='|'){
                if(isTrue==true){
                    ans=(ans+lt*rt+lt*rf+lf*rt)%1003;
                }
                else ans=(ans+lf*rf)%1003;
            }
        }
        return m[temp]=ans;
    }
    int countWays(int N, string S){
        // code here
        m.clear();
        return solve(S, 0, N - 1, true);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends