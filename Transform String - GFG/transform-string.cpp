//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        
        vector<int>freq(256, 0);
        
        for(char i : A) ++freq[i];
        
        for(char i : B) --freq[i];
        
        for(int i : freq)   if(i != 0)  return -1;
        
        int steps = 0, i = A.size() - 1, j = B.size() - 1;
        
        while(i >= 0 && j >= 0){
            
            if(A[i] == B[j])    --j;
            
            else    ++steps;
            
            --i;
        }
        
        return steps;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends