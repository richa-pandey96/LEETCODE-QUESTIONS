class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // Step 1: Combine both sentences into one string
    string combined = s1 + " " + s2;
    
    // Step 2: Use a hash map to count the frequency of each word
    unordered_map<string, int> wordCount;
    string word;
    stringstream ss(combined); // Used to split the combined string by spaces
    
    // Step 3: Split the words and store their frequency in the hash map
    while (ss >> word) {
        wordCount[word]++;
    }
    
    // Step 4: Collect words that appear exactly once (uncommon words)
    vector<string> result;
    for (const auto& entry : wordCount) {
        if (entry.second == 1) {  // Uncommon words appear only once
            result.push_back(entry.first);
        }
    }
    
    return result;

    
        
    }
};