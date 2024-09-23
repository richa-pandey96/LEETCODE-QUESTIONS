class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Split the string s into words
        vector<string> words;
        string word;
        stringstream ss(s);
        while (ss >> word) {
            words.push_back(word);
        }

        // If the number of pattern characters and words differ, return false
        if (pattern.length() != words.size()) {
            return false;
        }

        // Create two hash maps for bijection
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        // Iterate through pattern and words simultaneously
        for (int i = 0; i < pattern.length(); ++i) {
            char c = pattern[i];
            string w = words[i];

            // Check pattern to word mapping
            if (charToWord.find(c) != charToWord.end()) {
                if (charToWord[c] != w) {
                    return false;
                }
            } else {
                charToWord[c] = w;
            }

            // Check word to pattern mapping
            if (wordToChar.find(w) != wordToChar.end()) {
                if (wordToChar[w] != c) {
                    return false;
                }
            } else {
                wordToChar[w] = c;
            }
        }

        return true;
    
        
    }
};