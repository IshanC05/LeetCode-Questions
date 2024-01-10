/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, unordered_map<int, vector<int>>&adj){
        if(!root)   return;
        
        inorder(root->left, adj);
        
        int u = root->val;
        
        if(root->left){
            int v1 = root->left->val;
            adj[u].push_back(v1);
            adj[v1].push_back(u);
        }
        
        if(root->right){
            int v1 = root->right->val;
            adj[u].push_back(v1);
            adj[v1].push_back(u);
        }
        inorder(root->right, adj);
    }
    int bfs(unordered_map<int, vector<int>>&adj, int src){
        queue<pair<int, int>>q;
        unordered_set<int>vis;
        
        q.push({src, 0});
        vis.insert(src);
        
        int res = 0;
        
        while(!q.empty()){
            
            int u = q.front().first;
            int level = q.front().second;
            q.pop();
            
            res = level;
            
            for(int &v : adj[u]){
                if(vis.find(v) == vis.end()){
                    vis.insert(v);
                    q.push({v, 1 + level});
                }
            }
            
        }
        
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>>adj;
        
        inorder(root, adj);
        
        return bfs(adj, start);       
    }
};