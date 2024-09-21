class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // If lengths are not the same, they can't be anagrams
    if (s.length() != t.length()) {
        return false;
    }

    // Create a hash map to count character frequencies
    unordered_map<char, int> charCount;

    // Increase count for characters in str1
    for (char ch : s) {
        charCount[ch]++;
    }

    // Decrease count for characters in str2
    for (char ch : t) {
        charCount[ch]--;
    }

    // Check if all character counts are zero
    for (auto count : charCount) {
        if (count.second != 0) {
            return false;
        }
    }

    return true;


        
    }
};