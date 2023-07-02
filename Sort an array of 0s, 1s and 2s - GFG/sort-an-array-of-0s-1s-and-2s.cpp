//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int l = 0, r = n - 1, mid = 0;
        
        while(mid <= r){
            if(a[mid] == 0){
                swap(a[mid++], a[l++]);
            }else if(a[mid] == 1){
                ++mid;
            }else{
                swap(a[mid], a[r--]);
            }
        }
        
        return;
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends