/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>res;
    void helper(Node* root){
        
        if(!root)   return;
        
        res.push_back(root->val);
        
        for(auto it : root->children){
            helper(it);
        }
        
    }
    vector<int> preorder(Node* root) {        
        res.clear();
        
        if(!root)   return res;
        
        helper(root);
        
        return res;
    }
};