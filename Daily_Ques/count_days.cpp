#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;

        // Step 1: Sort the meetings by start day
        sort(meetings.begin(), meetings.end());

        // Step 2: Merge overlapping intervals
        vector<pair<int, int>> merged;
        int start = meetings[0][0], end = meetings[0][1];

        for (int i = 1; i < meetings.size(); ++i) {
            if (meetings[i][0] <= end) {
                // Overlapping interval -> merge
                end = max(end, meetings[i][1]);
            } else {
                // Non-overlapping -> add the previous interval
                merged.emplace_back(start, end);
                start = meetings[i][0];
                end = meetings[i][1];
            }
        }
        merged.emplace_back(start, end);  // Add the last interval

        // Step 3: Count the free days
        int freeDays = 0;

        // Free days before the first meeting
        if (merged[0].first > 1) {
            freeDays += merged[0].first - 1;
        }

        // Free days between merged intervals
        for (int i = 1; i < merged.size(); ++i) {
            freeDays += merged[i].first - merged[i - 1].second - 1;
        }

        // Free days after the last meeting
        if (merged.back().second < days) {
            freeDays += days - merged.back().second;
        }

        return freeDays;
    }
};
