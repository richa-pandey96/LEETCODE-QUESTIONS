
        class Solution {
public:
    // Helper function to count the steps between prefix and prefix + 1 within the limit n
    int countSteps(long prefix, long n) {
        long current = prefix;
        long next_prefix = prefix + 1;
        int steps = 0;
        
        // Count the number of numbers between prefix and next_prefix
        while (current <= n) {
            steps += min(n + 1, next_prefix) - current;
            current *= 10;
            next_prefix *= 10;
        }
        
        return steps;
    }

    // Main function to find the k-th smallest number in lexicographical order
    int findKthNumber(int n, int k) {
        int current = 1;  // Start at 1
        k--;  // Since the first number (1) is already considered

        // Loop until we find the k-th number
        while (k > 0) {
            int steps = countSteps(current, n);
            if (steps <= k) {
                // Move to the next sibling prefix
                current++;
                k -= steps;  // Subtract the steps from k
            } else {
                // Move down the tree to a deeper level
                current *= 10;
                k--;  // We count the current number
            }
        }

        return current;
    }
};
