//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    
    bool helper(vector<int>&arr, int dist, int cows){
        
        int last = arr[0], placed = 1;
        
        for(int i = 1; i < arr.size(); i++){
            
            if(arr[i] - last >= dist){
                
                last = arr[i];
                
                ++placed;
                
            }
            
        }
        
        return placed >= cows;        
    }
    
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        sort(stalls.begin(), stalls.end());
        
        int l = 1, h = stalls[n - 1] - stalls[0], ans = h;
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            if(helper(stalls, mid, k)){
                
                ans = mid;
                
                l = mid + 1;
                
            }
            
            else    h = mid - 1;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends