/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*>parent;
    
    vector<int>BFS(TreeNode* root, int k){
        
        unordered_set<TreeNode*>visited;
        queue<TreeNode*>q;
        
        q.push(root);
        visited.insert(root);
        
        while(!q.empty()){
            
            if(k == 0)
                break;
                
            int qSize = q.size();
            
            for(int i = 0; i < qSize; i++){
                
                TreeNode* front = q.front();
                q.pop();
                
                if(front->left != NULL && visited.find(front->left) == visited.end()){
                    q.push(front->left);
                    visited.insert(front->left);
                }
                
                if(front->right != NULL && visited.find(front->right) == visited.end()){
                    q.push(front->right);
                    visited.insert(front->right);
                }
                
                if(parent.find(front) != parent.end() && visited.find(parent[front]) == visited.end()){
                    q.push(parent[front]);
                    visited.insert(parent[front]);
                }
                
            }
            
            --k;
        }
        
        vector<int>res;
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            res.push_back(f->val);
        }
        
        return res;
    }
    
    void fillParent(TreeNode* root){
        if(!root)   return;
        
        if(root->left != NULL)
            parent[root->left] = root;
        fillParent(root->left);
        
        if(root->right != NULL)
            parent[root->right] = root;
        fillParent(root->right);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent.clear();
        fillParent(root);
        return BFS(target, k);
    }
};