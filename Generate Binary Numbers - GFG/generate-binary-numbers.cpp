//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	queue<string>q;
	vector<string>ans;
	
	q.push("1");
	
	for(int i = 1; i <= N; i++){
	    string top = q.front();
	    q.pop();
	    
	    ans.push_back(top);
	    q.push(top + "0");
	    q.push(top + "1");
	}
	
	return ans;
}


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends