class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
         // Map to store the sorted string as the key and the corresponding group of anagrams as the value
    unordered_map<string, vector<string>> anagramMap;

    // Iterate through each string in the input list
    for (string& str : strs) {
        // Sort the string to use it as the key
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());

        // Add the original string to the list corresponding to the sorted string key
        anagramMap[sortedStr].push_back(str);
    }

    // Prepare the result by collecting all the grouped anagrams
    vector<vector<string>> result;
    for (auto& pair : anagramMap) {
        result.push_back(pair.second);
    }

    return result;

        
    }
};
// //OR
// // Hash map to store frequency array as key and corresponding group of anagrams as value
//     unordered_map<string, vector<string>> anagramMap;

//     // Iterate through each string in the input list
//     for (const string& str : strs) {
//         // Create a frequency array of size 26 for 'a' to 'z'
//         vector<int> frequency(26, 0);

//         // Count the frequency of each character in the string
//         for (char c : str) {
//             frequency[c - 'a']++;
//         }

//         // Convert the frequency array into a string to use it as a key
//         string key = "";
//         for (int count : frequency) {
//             key += to_string(count) + "#";  // "#" is used to separate counts of different characters
//         }

//         // Add the original string to the list corresponding to the frequency key
//         anagramMap[key].push_back(str);
//     }

//     // Prepare the result by collecting all the grouped anagrams
//     vector<vector<string>> result;
//     for (auto& pair : anagramMap) {
//         result.push_back(pair.second);
//     }

//     return result;
