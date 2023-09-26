//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        set<vector<int>>st;
        
        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                int target = k - arr[i] - arr[j];
                int l = j + 1, r = n - 1;
                while(l < r){
                    int curSum = arr[l] + arr[r];
                    if(curSum == target){
                        st.insert({arr[i], arr[j], arr[l], arr[r]});
                        ++l;
                        --r;
                    }
                    else if(curSum > target)   --r;
                    else    ++l;
                }
            }
        }
        
        vector<vector<int>>ans(st.begin(), st.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends