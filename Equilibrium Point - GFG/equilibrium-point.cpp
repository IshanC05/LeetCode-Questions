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
        long long lsum = 0, rsum = 0;
        for(int i = n-1; i>0;i--){
            rsum = rsum + a[i];
        }
        int idx = -1;
        for(int i=0;i<n-1;i++){
            lsum = lsum + a[i];
            rsum = rsum - a[i + 1];
            if(lsum == rsum){
                idx = i + 2;
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