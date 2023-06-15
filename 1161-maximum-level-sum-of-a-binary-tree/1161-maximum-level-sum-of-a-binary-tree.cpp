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
    int maxLevelSum(TreeNode* root) {
        // Using BFS
        queue<TreeNode*>pendingNodes;
        int maxSum = root->val, maxLevel = 1, curLevel = 1;
        pendingNodes.push(root);
        
        while(!pendingNodes.empty()){
            int qSize = pendingNodes.size(), curSum = 0;
            for(int i = 0; i < qSize; i++){
                TreeNode* front = pendingNodes.front();
                pendingNodes.pop();
                curSum += front->val;
                if(front->left){
                    pendingNodes.push(front->left);
                }
                if(front->right){
                    pendingNodes.push(front->right);
                }
            }
            if(curSum > maxSum){
                maxSum = curSum;
                maxLevel = curLevel;
            }
            ++curLevel;
        }
        
        return maxLevel;
    }
};