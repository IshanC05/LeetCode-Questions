//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        map<int,int>freq;
        for(int i = 0; i < n; i++){
            ++freq[arr[i]];
        }
        
        int curMax = 0, curFreq = INT_MAX;
        for(auto it = freq.begin(); it != freq.end(); it++){
            if(curMax < it->first and curFreq >= it->second){
                curMax = it->first;
                curFreq = it->second;
            }
        }
        return curMax;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends