class Solution {
public:
    
    bool BFS(int n, unordered_map<int,vector<int>>&grid, vector<bool>&vis, int root){
        
        queue<int>q;
        q.push(root);
        
        vis[root] = true;
        
        bool ans = true;
        
        while(!q.empty()){
            
            int u = q.front();
            q.pop();
            
            for(auto &v : grid[u]){
                
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);                    
                }
                else    return false;
            }
            
        }
        
        return ans;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        unordered_map<int,vector<int>>grid;
        
        for(int i = 0; i < n; i++){
            
            int u = i;
            int v1 = leftChild[u];
            int v2 = rightChild[u];
            
            if(v1 != -1)    grid[u].push_back(v1);
            if(v2 != -1)    grid[u].push_back(v2);
        }
        
        int root = findRoot(n, leftChild, rightChild);
        
        if(root == -1)  return false;
        
        vector<bool>vis(n, false);
        
        bool isFirst = false;
        
        for(int i = 0; i < n; i++){
            
            if(!vis[i]){
                
                if(!isFirst){
                    isFirst = true;
                    if(BFS(n, grid, vis, root) == false)      return false;
                }
                
                else    return false;
            }
            
        }
        
        return true;
    }
    
    int findRoot(int n, vector<int>& left, vector<int>& right) {
        unordered_set<int> children;
        children.insert(left.begin(), left.end());
        children.insert(right.begin(), right.end());
        
        for (int i = 0; i < n; i++) {
            if (children.find(i) == children.end()) {
                return i;
            }
        }
        
        return -1;
    }
};