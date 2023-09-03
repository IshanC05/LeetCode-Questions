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
    vector<int> rightSideView(TreeNode *root)
    {

        vector<int> ans;

        if (!root)
            return ans;

        queue<TreeNode *> pendingNodes;

        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {

            int qSize = pendingNodes.size();

            for (int i = 0; i < qSize; i++)
            {

                TreeNode *front = pendingNodes.front();

                pendingNodes.pop();

                if (front->left)
                    pendingNodes.push(front->left);

                if (front->right)
                    pendingNodes.push(front->right);

                if (i == qSize - 1)
                    ans.push_back(front->val);
            }
        }

        return ans;
    }
};