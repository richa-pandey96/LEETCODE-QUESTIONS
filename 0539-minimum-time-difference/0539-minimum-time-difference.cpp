class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        
         int n = timePoints.size();  // Number of time points
    vector<int> minutes(n);     // Vector to store time points in minutes

    // Convert "HH:MM" to total minutes since midnight
    for (int i = 0; i < n; ++i) {
        string time = timePoints[i];
        string hourSubstr = time.substr(0, 2);  // Extract the "HH" part
        string minSubstr = time.substr(3, 2);   // Extract the "MM" part

        int hourInt = stoi(hourSubstr);  // Convert "HH" to integer
        int minInt = stoi(minSubstr);    // Convert "MM" to integer

        minutes[i] = hourInt * 60 + minInt;  // Convert to total minutes
    }

    // Sort the time points in ascending order of minutes
    sort(begin(minutes), end(minutes));

    // Initialize the result to a large value
    int result = INT_MAX;

    // Compute the minimum difference between consecutive times
    for (int i = 1; i < n; ++i) {
        result = min(result, minutes[i] - minutes[i - 1]);
    }

    // Handle the wrap-around case (from the last time of the day to the first time)
    result = min(result, 24 * 60 - minutes[n - 1] + minutes[0]);

    return result;

    }
};