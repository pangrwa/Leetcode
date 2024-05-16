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
    bool evaluateTree(TreeNode* root) {
        // no handling of null because question context guarentees
        if (root->val == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        } else if (root->val == 3) {
            return evaluateTree(root->left) && evaluateTree(root->right); 
        } else { // leaf node
            return root->val; 
        }
    }
};

/*
post order traversal 
full binary tree -> either 0 or 2 child
-> leaf node -> val | False | False
-> non-leaf node depends on val
*/