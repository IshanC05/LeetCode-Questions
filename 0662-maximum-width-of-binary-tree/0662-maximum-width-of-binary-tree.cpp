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
    int widthOfBinaryTree(TreeNode* root) {
        
        int res = 0;
        
        if(!root)   return res;
        
        deque<pair<TreeNode*, long long>>dq;
        dq.push_back({root, 0});
        
        while(!dq.empty()){
            
            int qSize = dq.size();
            
            int leftIdx = dq.front().second;
            int rightIdx = dq.back().second;
            
            res = max(res, rightIdx - leftIdx + 1);
            
            for(int i = 0; i < qSize; i++){
                
                TreeNode* front = dq.front().first;
                int idx = dq.front().second;
                dq.pop_front();
                
                if(front->left){
                    dq.push_back({front->left, 2*(idx*1LL) + 1});
                }
                
                if(front->right){
                    dq.push_back({front->right, 2*(idx*1LL) + 2});
                }
                
            }
            
        }
        
        return res;
        
    }
};