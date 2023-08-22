//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
int Count(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int count = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int zeroCount = 0;
            
            if (matrix[i][j] == 1) {
                // Check each of the 8 possible neighboring cells
                if (i - 1 >= 0 && j - 1 >= 0 && matrix[i - 1][j - 1] == 0)
                    zeroCount++;
                if (i - 1 >= 0 && matrix[i - 1][j] == 0)
                    zeroCount++;
                if (i - 1 >= 0 && j + 1 < cols && matrix[i - 1][j + 1] == 0)
                    zeroCount++;
                if (j - 1 >= 0 && matrix[i][j - 1] == 0)
                    zeroCount++;
                if (j + 1 < cols && matrix[i][j + 1] == 0)
                    zeroCount++;
                if (i + 1 < rows && j - 1 >= 0 && matrix[i + 1][j - 1] == 0)
                    zeroCount++;
                if (i + 1 < rows && matrix[i + 1][j] == 0)
                    zeroCount++;
                if (i + 1 < rows && j + 1 < cols && matrix[i + 1][j + 1] == 0)
                    zeroCount++;
                
                // Check if the count of neighboring zeros is even
                if (zeroCount != 0 && zeroCount % 2 == 0)
                    count++;
            }   
        }
    }
    
    return count;
}


};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends