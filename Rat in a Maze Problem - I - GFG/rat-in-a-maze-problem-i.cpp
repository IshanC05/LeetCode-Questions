//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> result;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string path = "";

        if (m[0][0] == 1) {
            visited[0][0] = true;
            findPaths(m, n, 0, 0, visited, path, result);
        }

        return result;
    }

private:
    bool isValid(int x, int y, int n, vector<vector<int>>& mat, vector<vector<bool>>& visited) {
        return (x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == 1 && !visited[x][y]);
    }

    void findPaths(vector<vector<int>>& mat, int n, int x, int y, vector<vector<bool>>& visited, string& path, vector<string>& result) {
        if (x == n - 1 && y == n - 1) {
            result.push_back(path);
            return;
        }

        // Possible directions: Up, Down, Left, Right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        char directions[] = {'U', 'D', 'L', 'R'};

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY, n, mat, visited)) {
                visited[newX][newY] = true;
                path.push_back(directions[i]);

                findPaths(mat, n, newX, newY, visited, path, result);

                // Backtrack
                visited[newX][newY] = false;
                path.pop_back();
            }
        }
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends