//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

int helper(string s1, string s2, int n){
    vector<vector<int>>t(n + 1, vector<int>(n + 1, 0));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            
            if(s1[i - 1] == s2[j - 1]){
                
                t[i][j] = 1 + t[i - 1][j - 1];
                
            }else{
                
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                
            }
            
        }
    }
    
    return t[n][n];
    
}
int minDeletions(string str1, int n) { 
    //complete the function here 
    string str2(str1.rbegin(), str1.rend());
    
    int lps = helper(str1, str2, n);
    
    return n - lps;
} 