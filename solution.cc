
// Given a binary tree, return the inorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,3,2].

// Note: Recursive solution is trivial, could you do it iteratively?

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> myStack;
        TreeNode *cur = root;
        while(cur || !myStack.empty()) {
            if(cur) {
                if(cur->left) {
                    myStack.push(cur);
                    cur = cur->left;
                } else {
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            } else {
                cur = myStack.top();
                res.push_back(cur->val);
                myStack.pop();
                cur = cur->right;
            }
        }
        return res;
    }
};
