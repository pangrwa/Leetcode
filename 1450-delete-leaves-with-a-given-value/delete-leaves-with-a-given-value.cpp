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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode dummyHead(0, root, nullptr); 
        dfs(&dummyHead, target); 
        return dummyHead.left;
    }

    bool dfs(TreeNode* root, int target) {
        if (root == NULL) {
            return false; 
        }
        if (dfs(root->left, target)) { // remove left
            root->left = NULL; 
        }
        if (dfs(root->right, target)) { // remove right
            root->right = NULL; 
        }
        return (!root->left) && (!root->right) && (root->val == target); 
    }
};

/*
DFS, someway to tell the leave to tell parent to disconnect
-> only can disconnect if no children and value == target
*/ 