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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            
            long long qSize = q.size(), sum = 0;
            
            for(int i = 0; i < qSize; i++){
                
                auto front = q.front();
                q.pop();
                
                if(front->left)     q.push(front->left);
                if(front->right)    q.push(front->right);
                
                sum += front->val;
            }
            
            res.push_back((double)sum / qSize);            
        }
        
        return res;
    }
};