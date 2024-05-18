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
    int moves;
    int distributeCoins(TreeNode* root) {
        moves = 0;
        dfs(root); 
        return moves; 
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0; 
        }
        // finds the # of coins given or required by children
        int leftCoins = dfs(root->left); 
        int rightCoins = dfs(root->right);
        // for leftCoins and rightCoins
        // +ve: coins to send back -> # number of moves to send up
        // -ve: coins needed -> # number of moves to send down
        moves += abs(leftCoins) + abs(rightCoins); 

        // calculate remaining/need coins back to parent
        int remainingCoins = root->val - 1; 
        return remainingCoins + leftCoins + rightCoins; 
    }
};

/*
simplify by just looking at root
1. if the root has enough to distrubte to its right and itself, 
    then the left child will never give back coins to parent
2. like wise if it's missing one, then its guarentee the l
    eft child will give back one coin because 
    the coins are theoretically == # of nodes
Just by distributing back the coins to the parent itself is the minimum
number of moves required to make every node has exactly one coin
** So you want to greedily distrubte the coins at the bottommost subtrees
to minimise movement of coins (postorder traversal)
Idea
At every subtree
1. dfs(left), dfs(right)
2. This gives use the number of coins needed/have from the left or the right
2. determine if cur.val has enough coins to distribute to the tree
    if not enough use (-ve) to represent how many coins you need 
*/