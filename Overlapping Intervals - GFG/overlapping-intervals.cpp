//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0] == b[0])    return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> overlappedInterval(vector<vector<int>>& arr) {
         // Code here
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end(), comp);
        
        int s = arr[0][0], e = arr[0][1];
        
        for(int i = 1; i < arr.size(); i++){
            
            int cs = arr[i][0], ce = arr[i][1];
            
            if(cs <= e){
                s = min(s, cs);
                e = max(e, ce);
            }else{
                ans.push_back({s, e});
                s = cs, e = ce;
            }
            
        }
        
        ans.push_back({s, e});
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends