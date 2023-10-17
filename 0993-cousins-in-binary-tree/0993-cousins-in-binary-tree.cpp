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
    // node-val, depth, parent
    unordered_map<int, pair<int,int>>mp;
    
    void inorder(TreeNode* root, int depth, int parent){
        
        if(!root)   return;
        
        inorder(root->left, depth + 1, root->val);
        mp[root->val] = make_pair(depth, parent);
        inorder(root->right, depth + 1, root->val);
        
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        inorder(root, 0, 0);
        
        if(!root)   return false;
        
        int dx = mp[x].first;
        int px = mp[x].second;
        
        int dy = mp[y].first;
        int py = mp[y].second;
        
        return (dx == dy && px != py);
    }
};