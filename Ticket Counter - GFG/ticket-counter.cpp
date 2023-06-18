//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
        int i = 1, j = N, temp = K;
        bool turn = 0;
        while(i != j){
            while(i != j and !turn and temp){
                ++i;
                --temp;
            }
            turn  = !turn;
            temp = K;
            while(i != j and turn and temp){
                --j;
                --temp;
            }
            turn = !turn;
            temp = K;
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