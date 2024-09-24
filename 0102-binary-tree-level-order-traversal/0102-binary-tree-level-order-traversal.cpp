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
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> result;  // To store the result of level order traversal.
        if (root == nullptr) return result;  // If the tree is empty, return an empty result.

        queue<TreeNode*> q;  // Queue for breadth-first traversal.
        q.push(root);  // Start from the root node.
        
        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at the current level.
            vector<int> currentLevel;  // List to store nodes at the current level.
            
            // Process each node at the current level.
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);  // Add the node's value to the current level.
                
                // Add the left child if it exists.
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                // Add the right child if it exists.
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            // After finishing the current level, add it to the result.
            result.push_back(currentLevel);
        }
        
        return result;  // Return the complete level order traversal.
        
    }
};