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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        // Base case
        if (!root) return -1;

        // BFS queue for level-order traversal
        queue<TreeNode*> queue;
        queue.push(root);

        // Min-heap (priority queue) to track the K largest sums
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        // Perform BFS
        while (!queue.empty()) {
            int size = queue.size(); // number of nodes at current level
            long long sum = 0; // sum of values at current level

            for (int i = 0; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();
                sum += node->val; // accumulate sum for the current level

                // Add child nodes to the queue for the next level
                if (node->left != nullptr) {
                    queue.push(node->left);
                }
                if (node->right != nullptr) {
                    queue.push(node->right);
                }
            }

            // Add the current level sum to the priority queue (min-heap)
            pq.push(sum);

            // Keep only the K largest sums in the priority queue
            if (pq.size() > k) {
                pq.pop(); // remove the smallest sum to maintain only K elements
            }
        }

        // If there are fewer than K levels, return -1
        if (pq.size() < k) {
            return -1;
        }

        // Return the Kth largest level sum (smallest in the min-heap)
        return pq.top();
    
        
    }
};