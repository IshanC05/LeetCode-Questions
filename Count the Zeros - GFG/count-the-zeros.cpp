//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lastIdx(int* arr, int n){
        int l = 0, h = n-1, ans = -1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(arr[mid] > 0){
                h = mid - 1;
            }else if(arr[mid] < 0){
                l = mid + 1;
            }else{
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }
    int countZeroes(int arr[], int n) {
        // code here
        reverse(arr, arr+n);
        int last = lastIdx(arr, n);
        if(last == -1){
            return 0;
        }
        return last + 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countZeroes(arr, n);
        cout << ans << "\n";
    }
    return 0;
}


// } Driver Code Ends