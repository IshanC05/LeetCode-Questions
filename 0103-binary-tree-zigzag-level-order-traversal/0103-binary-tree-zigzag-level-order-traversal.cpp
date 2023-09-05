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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        
        if(!root)   return ans;
        
        deque<TreeNode*>pendingNodes;
        
        pendingNodes.push_back(root);
        
        // 1 : L -> R || 0 : R -> L         
        bool leftToRight = true;
        
        while(!pendingNodes.empty()){
            
            int qSize = pendingNodes.size();
            
            vector<int>temp(qSize);
    
            for(int i = 0; i < qSize; i++){

                TreeNode* front = pendingNodes.front();

                pendingNodes.pop_front();

                if(front->left)     pendingNodes.push_back(front->left);

                if(front->right)    pendingNodes.push_back(front->right);

                int idx = leftToRight ? i : qSize - i - 1;
                
                temp[idx] = front->val;

            }
                
            
            leftToRight = !leftToRight;
            
            ans.push_back(temp);
            
        }
        
        return ans;
        
    }
};