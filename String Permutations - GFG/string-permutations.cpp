//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
        void solve(string& s){
        
        int i, j, n = s.size();
        
        if(n <= 1)  return;
        
        for(i = n - 2; i >= 0; --i){
            
            if(s[i] < s[i + 1])   break;
            
        }
        
        if(i < 0)   reverse(s.begin(), s.end());
        
        else{
            
            for(j = n - 1; j >= 0; --j){
                
                if(s[j] > s[i]){
                    
                    swap(s[j], s[i]);
                    
                    break;
                    
                }
                
            }
            
            reverse(s.begin() + i + 1, s.end());
            
        }
        
        
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        // sort(S.begin(), S.end());
        
        int num = 1;
        
        for(int i = S.size(); i > 0; i--)   num = num * i;
        
        vector<string>ans;
        
        ans.push_back(S);
        
        while(ans.size() != num){
            
            solve(S);
            
            ans.push_back(S);
            
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
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