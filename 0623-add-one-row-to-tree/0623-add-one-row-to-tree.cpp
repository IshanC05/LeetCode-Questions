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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        int currDepth = 1;
        bool flag = false;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty() && !flag) {
            int qSize = q.size();

            for (int i = 0; i < qSize; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (currDepth == depth - 1) {
                    flag = true;

                    TreeNode* oldLeftSubTree = nullptr;
                    TreeNode* oldRightSubTree = nullptr;

                    TreeNode* newLeftNode = new TreeNode(val);
                    TreeNode* newRightNode = new TreeNode(val);

                    if (front->left != nullptr) oldLeftSubTree = front->left;
                    if (front->right != nullptr) oldRightSubTree = front->right;

                    front->left = newLeftNode;
                    front->right = newRightNode;

                    newLeftNode->left = oldLeftSubTree;
                    newRightNode->right = oldRightSubTree;
                } else {
                    if (front->left != nullptr) q.push(front->left);
                    if (front->right != nullptr) q.push(front->right);
                }
            }

            ++currDepth;
        }

        return root;
    }
};