//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int calcDigitSum(int n){
        int ans = 0;
        
        while(n){
            ans += (n % 10);
            n = (n / 10);
        }
        
        return ans;
    }
  
    int isPossible(int N, int arr[]) {
        // code here
        int sum = 0;
        
        for(int i = 0; i < N; i++){
            sum += calcDigitSum(arr[i]); 
        }
        
        return !(sum % 3);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends