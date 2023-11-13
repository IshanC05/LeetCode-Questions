//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int t[1001][1001];
    long long helper(int coins[], int N, int sum){
        
        if(N == 0)  return sum == 0 ? 1 : 0;
        
        if(t[N][sum] != -1)     return t[N][sum];
        
        long long int res = helper(coins, N - 1, sum);
        
        if(coins[N - 1] <= sum)
            res += helper(coins, N, sum - coins[N - 1]);
            
        return t[N][sum] = res;
        
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        memset(t, -1, sizeof(t));
        
        return helper(coins, N, sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends