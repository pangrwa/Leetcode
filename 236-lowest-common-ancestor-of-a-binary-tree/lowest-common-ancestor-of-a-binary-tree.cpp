/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        // itself is the ancestor, send itself up
        if (root->val == p->val || root->val == q->val) {
            return root; 
        }
        TreeNode* leftAncestor = lowestCommonAncestor(root->left, p, q); 
        TreeNode* rightAncestor = lowestCommonAncestor(root->right, p, q);
        // left and right contains an ancestor, so itself is the common
        if (leftAncestor != nullptr && rightAncestor != nullptr) {
            return root; 
        }
        // only left side contains the ancestor
        if (leftAncestor != nullptr && rightAncestor == nullptr) {
            return leftAncestor; 
        }
        // only right side contains the ancestor
        if (rightAncestor != nullptr && leftAncestor == nullptr) {
            return rightAncestor; 
        }
        // this substree doesn't contain ancestor at all
        return nullptr; 

        
    }
};