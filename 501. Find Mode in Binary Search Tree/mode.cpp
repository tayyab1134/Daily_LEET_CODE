/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        int currentCount = 0, maxCount = 0, prev = INT_MIN;
        inOrderTraversal(root, modes, currentCount, maxCount, prev);
        return modes;
    }

private:
    void inOrderTraversal(TreeNode* node, vector<int>& modes, int& currentCount,
                          int& maxCount, int& prev) {
        if (!node)
            return;

        inOrderTraversal(node->left, modes, currentCount, maxCount, prev);

        if (node->val == prev) {
            currentCount++;
        } else {
            currentCount = 1;
            prev = node->val;
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            modes = {node->val};
        } else if (currentCount == maxCount) {
            modes.push_back(node->val);
        }

        inOrderTraversal(node->right, modes, currentCount, maxCount, prev);
    }
};