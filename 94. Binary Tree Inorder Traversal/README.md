Easy

Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100


⏱️ Time Complexity: O(n)
Each node is visited exactly once.

n is the number of nodes in the tree.

📦 Space Complexity: O(h)
h is the height of the tree.

In the worst case (skewed tree), the stack holds up to n nodes → O(n)

In average/balanced cases → O(log n)