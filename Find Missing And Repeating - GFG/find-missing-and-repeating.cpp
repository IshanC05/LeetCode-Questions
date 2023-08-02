//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> result(2);
        int orignalSum = 0;
        int currSum = 0;
        for (int i = 0; i < n; i++) {
            int orignalElement = abs(arr[i]);
            int index = orignalElement - 1;
            if (arr[index] < 0) {
                result[0] = orignalElement;
            }
            arr[index] = -arr[index];
            orignalSum += (i + 1);
            currSum += orignalElement;
        }
        result[1] = orignalSum - (currSum - result[0]);
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends