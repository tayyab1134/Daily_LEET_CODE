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
    int cameras = 0;

    int dfs(TreeNode* node) {
        if (!node) return 1;

        int left = dfs(node->left);
        int right = dfs(node->right);

        if (left == 0 || right == 0) {
            cameras++;
            return 2;
        }

        if (left == 2 || right == 2) {

            return 1;
        }

        return 0;
    }

public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) cameras++; 
        return cameras;
    }
};