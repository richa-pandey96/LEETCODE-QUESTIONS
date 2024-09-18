class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        // Check if lengths of both strings are not equal
    if (s.length() != t.length()) {
        return false;
    }

    // Create a hash map to store character mappings
    unordered_map<char, char> charMappingMap;

    for (int i = 0; i < s.length(); i++) {
        char original = s[i];       // Get the ith character from the first string
        char replacement = t[i];    // Get the ith character from the second string

        // If the character from the first string is not mapped yet
        if (charMappingMap.find(original) == charMappingMap.end()) {
            // Ensure the value isn't already mapped to some other key
            for (auto& pair : charMappingMap) {
                if (pair.second == replacement) {
                    return false; // Already mapped to another key, so fail
                }
            }
            charMappingMap[original] = replacement; // Add the mapping
        }
        // If it is already mapped, check if it maps to the expected character
        else {
            if (charMappingMap[original] != replacement) {
                return false; // Mapped to different character, so fail
            }
        }
    }

    return true; // All characters are properly mapped

        
    }
};