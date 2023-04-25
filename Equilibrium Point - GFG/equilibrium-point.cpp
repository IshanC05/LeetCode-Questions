//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        if(n == 1){
            return n;
        }
        long long left[n] = {0};
        long long right[n] = {0};
        left[0] = 0, right[n-1] = 0;
        for(int i=1;i<n;i++){
            left[i] = left[i - 1] + a[i - 1];
        }
        for(int i=n-2;i>=0;--i){
            right[i] = right[i + 1] + a[i + 1];
        }
        int idx = -1;
        for(int i=0;i<n;i++){
            if(left[i] == right[i]){
                idx = i + 1;
                break;
            }
        }
        return idx;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends