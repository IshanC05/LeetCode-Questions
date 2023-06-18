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
    vector<int>temp;
    void getPreOrder(TreeNode* root){
        if(!root){
            return;
        }
        temp.push_back(root->val);
        getPreOrder(root->left);
        getPreOrder(root->right);
    }
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        getPreOrder(root);
        root->left = nullptr, root->right = nullptr;
        TreeNode* curr = root;
        for(int i = 1; i < temp.size(); i++){
            TreeNode* newNode = new TreeNode(temp[i]);
            curr->right = newNode;
            curr = curr->right;
        }
        return;
    }
};