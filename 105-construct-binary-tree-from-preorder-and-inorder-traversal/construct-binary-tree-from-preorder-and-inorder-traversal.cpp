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
    unordered_map<int, int> inOrderMap;
    int preOrderPointer = 0;
    int size;  
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        size = preorder.size(); 
        for (int i = 0; i < inorder.size(); ++i) {
            inOrderMap[inorder[i]] = i;
        }
        return dfs(preorder, inorder, 0, inorder.size() -1); 
    }

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (preOrderPointer >= size || left > right || right < left) {
            return nullptr; // nullchild
        }
        int inOrderIdx = inOrderMap[preorder[preOrderPointer]];
        TreeNode* cur = new TreeNode(inorder[inOrderIdx]);
        preOrderPointer++; // only do it once you create a valid node
        cur->left = dfs(preorder, inorder, left, inOrderIdx - 1); 
        cur->right = dfs(preorder, inorder, inOrderIdx + 1, right); 
        return cur; 
    }
};

/*
preorder: root, left, right
inorder: left, root, right

base case: if the middle node has no range of values left (left == right)
    it's a leaf, and should return

from the preorder determine the middle node, decide what range of values
    should be on its left child or the right child
-> becomes the subproblem of solving the left child and the right child
-> to do this efficiently we must be able to find the idx in the inorder traversal
    quickly hence we can use a hashmap


dfs(leftpointer, rightpointer) these pointer represents the 
    boundes of the inorder
recursive function
1. if the leftpointer = rightpointer
    - build a node with the current PreOrder pointer and return
2. base on the preorder point, find the idx in the Inorder
    -> find the left and right bound respectively for its children
    -> before each call remember to increment the PreOrder pointer
    -> solve left, solve right

preOrder pointer = 2
        [0, 1]
    1     [2, 1]
*/ 