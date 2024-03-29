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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)   return root;
        
        if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        }else if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }
        else{
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }else if(!root->left){
                TreeNode* temp = root->right;
                root->right = nullptr;
                delete root;
                return temp;
            }else if(!root->right){
                TreeNode* temp = root->left;
                root->left = nullptr;
                delete root;
                return temp;
            }else{
                TreeNode* minNode = root->right;
                while(minNode->left){
                    minNode = minNode->left;
                }
                int rightMin = minNode->val;
                root->val = rightMin;
                root->right = deleteNode(root->right, rightMin);
                return root;
            }
        }
    }
};