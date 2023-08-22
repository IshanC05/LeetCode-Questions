//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    long long maxTip(int a[], int b[], int n, int x, int y) {
      vector<pair<int,int>>diff(n);
      for(int i=0;i<n;i++){
          diff[i] = {abs(a[i]-b[i]),i};
      }
      int ans =0;
      if(x>n)
      x =n;
      if(y>n)
       y=n;
      auto cmp = [](pair<int,int>&p1, pair<int,int>&p2){
        return p1.first>p2.first;  
      };
      
      sort(diff.begin(),diff.end(),cmp);
      for(auto p:diff){
      //    cout<<a[p.second] << " " <<b[p.second] <<endl;
          if(a[p.second]>b[p.second] && x>0){
              ans+=a[p.second];
              x--;
          } else if(b[p.second]>a[p.second] && y>0){
              ans+=b[p.second];
              y--;
          } else if(b[p.second]==a[p.second]){
                ans+=a[p.second];
          } else if(x){
              ans+=a[p.second];
              x--;
          } else if(y){
              ans+=b[p.second];
              y--;
          }
        //  cout<<x<<" "<<y<<" "<<ans<<endl;
          
      }
       
          return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        Solution obj;
        auto ans = obj.maxTip(a, b, n, x, y);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends