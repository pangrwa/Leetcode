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
    stack<string> path;
    vector<string> res;

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root); 
        return res;
    }

    void dfs(TreeNode* root) {
        path.push(std::to_string(root->val));
        if (!root->left && !root->right) { // no children
            string str = buildPath(); 
            res.push_back(str); 
        } 
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right); 
        path.pop();
    }

    string buildPath() {
        string res = "";
        stack<string> copy = path;
        while (!copy.empty()) {
            if (copy.size() == 1) {
                res = copy.top() + res;
                copy.pop(); 
            } else {
                res = "->" + copy.top() + res;
                copy.pop(); 
            }
        }
        return res; 
    }
};