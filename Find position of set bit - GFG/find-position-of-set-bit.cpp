//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        
        int pos = 0, oneC = 0;
        
        if(N == 0)  return -1;
        
        while(N){
            
            if(N & 1){
                
                ++oneC;
                
                if(oneC > 1)    return -1;
                
            }
            
            N = (N >> 1);
            
            ++pos;
            
        }
        
        return pos;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends