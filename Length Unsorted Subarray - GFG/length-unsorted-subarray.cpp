//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
vector<int> printUnsorted(int arr[], int n) {
    if (n < 2) {
        return {0, 0};
    }

    int i = 0, j = n - 1;

    while (i < n - 1 && arr[i] <= arr[i + 1]) {
        ++i;
    }

    if (i == n - 1) {
        return {0, 0};
    }

    while (j > 0 && arr[j] >= arr[j - 1]) {
        --j;
    }

    int min_val = arr[i], max_val = arr[i];
    for (int k = i; k <= j; ++k) {
        min_val = min(min_val, arr[k]);
        max_val = max(max_val, arr[k]);
    }

    while (i > 0 && arr[i - 1] > min_val) {
        --i;
    }

    while (j < n - 1 && arr[j + 1] < max_val) {
        ++j;
    }

    return {i, j};
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
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

// } Driver Code Ends