class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;  // To store the element and its index
    
    for (int i = 0; i < nums.size(); ++i) {
        // If the current element is already in the hashmap
        if (hashmap.find(nums[i]) != hashmap.end()) {
            int j = hashmap[nums[i]];  // Get the previous index of this element
            
            // If the indices are within the distance k
            if (abs(i - j) <= k) {
                return true;
            }
        }
        
        // Update the hashmap with the current index of the element
        hashmap[nums[i]] = i;
    }
    
    return false;  // No duplicates found within the given range

        
    }
};