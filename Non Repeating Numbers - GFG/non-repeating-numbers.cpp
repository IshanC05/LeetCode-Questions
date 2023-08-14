//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        
        unordered_map<int,int>mp;
        
        for(int i : nums)   ++mp[i];
        
        int a = -1, b = -1;
        
        for(auto it : mp){
            
            if(it.second == 1){
                
                if(a == -1)     a = it.first;
                
                else    b = it.first;
                
            }
            
        }
        
        return {min(a,b), max(a,b)};
        
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends