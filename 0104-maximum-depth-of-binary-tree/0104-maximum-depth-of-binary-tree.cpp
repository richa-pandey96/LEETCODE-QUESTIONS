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
    int maxDepth(TreeNode* root) {
         if (root == nullptr) {
            return 0;  // If the tree is empty, return 0.
        }
        
        queue<TreeNode*> elementQueue;
        elementQueue.push(root);
        int numberOfLevels = 0;
        
        while (!elementQueue.empty()) {
            int nodeCountAtLevel = elementQueue.size();
            
            // Dequeue all the nodes present at the current level and add their children to the queue.
            while (nodeCountAtLevel > 0) {
                TreeNode* element = elementQueue.front();
                elementQueue.pop();
                
                if (element->left != nullptr) {
                    elementQueue.push(element->left);
                }
                if (element->right != nullptr) {
                    elementQueue.push(element->right);
                }
                
                nodeCountAtLevel--;
            }
            numberOfLevels++;
        }
        
        return numberOfLevels;
        
    }
};