//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void find_permutations_helper(string& S, int start, vector<string>& result) {
        if (start == S.length()) {
            result.push_back(S);
            return;
        }
    
        for (int i = start; i < S.length(); ++i) {
            swap(S[start], S[i]);
            find_permutations_helper(S, start + 1, result);
            swap(S[start], S[i]); // Backtrack to restore the original string for the next iteration
        }
    }
    
    vector<string> permutation(string& S) {
        vector<string> result;
        find_permutations_helper(S, 0, result);
        sort(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends