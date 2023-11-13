//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int t[1001][1001];

    int helper(int n, int w, int *profit, int *weight){
    
        if(n == 0)  return 0;
    
        if(t[n][w] != -1)   return t[n][w];
    
        int res = 0;
    
        if(weight[n - 1] <= w){
            res = profit[n - 1] + helper(n, w - weight[n - 1], profit, weight);
        }
    
        res = max(helper(n - 1, w, profit, weight), res);
    
        return t[n][w] = res;
    }

  
    int cutRod(int price[], int n) {
        //code here
        memset(t, -1, sizeof(t));
        
        int weight[n];
        
        for(int i = 0; i < n; i++)
            weight[i] = i + 1;
            
        return helper(n, n, price, weight);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends