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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int qSize = q.size();
            vector<int> levelValues;

            for (int i = 0; i < qSize; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (front) {
                    levelValues.push_back(front->val);
                    q.push(front->left);
                    q.push(front->right);
                } else {
                    levelValues.push_back(INT_MIN);
                }
            }

            int left = 0;
            int right = levelValues.size() - 1;

            while (left < right) {
                if (levelValues[left] != levelValues[right]) {
                    return false;
                }
                left++;
                right--;
            }
        }

        return true;
    }
};