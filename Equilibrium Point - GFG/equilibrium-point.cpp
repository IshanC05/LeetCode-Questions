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
        if(n == 1)  return n;
        
        int idx = -1;
        
        long long lsum = 0, rsum = 0;
        
        for(int i = 0; i < n; i++)  
            rsum += a[i];
            
        for(int i = 0; i < n; i++){
            rsum -= a[i];
            if(lsum == rsum)    return i + 1;
            lsum += a[i];
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