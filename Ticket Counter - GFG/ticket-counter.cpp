//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        int i = 1, j = N;
        bool turn = false;
        while (i != j) {
            if (!turn) {
                i += K;
                if (i >= j)
                    return j;
            } else {
                j -= K;
                if (j <= i)
                    return i;
            }
            turn = !turn;
        }
        return i;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends