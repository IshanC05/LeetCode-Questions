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
    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        
        if(!root)   return res;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            
            int maxVal = INT_MIN;
            int qSize = q.size();
            
            for(int i = 0; i < qSize; i++){
                
                TreeNode* front = q.front();
                q.pop();
                
                if(front->left)     q.push(front->left);
                if(front->right)     q.push(front->right);
                
                maxVal = max(maxVal, front->val);
            }
            
            res.push_back(maxVal);            
        }
        
        return res;
    }
};