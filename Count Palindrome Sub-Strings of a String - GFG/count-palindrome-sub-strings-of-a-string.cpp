//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends

int dp[501][501];
int CountPS(char s[], int n)
{
    //code here
    int res = 0;

    // Initialize the dp array to all zeros
    memset(dp, 0, sizeof(dp));

    // Length 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        // ++res;
    }

    // Length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            ++res;
        }
    }

    // Length >= 3
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                ++res;
            }
        }
    }

    return res;
    
}