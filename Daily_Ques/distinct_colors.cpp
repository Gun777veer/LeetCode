#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        // Map to store current color for each ball.
        unordered_map<int, int> ballColor;
        // Map to store count for each color.
        unordered_map<int, int> colorCount;
        vector<int> result;
        
        for (const auto& query : queries) {
            int ball = query[0];
            int newColor = query[1];
            
            // Check if the ball is already colored.
            if (ballColor.find(ball) != ballColor.end()) {
                int oldColor = ballColor[ball];
                // Only update if the new color is different.
                if (oldColor != newColor) {
                    // Decrease the count for the old color.
                    colorCount[oldColor]--;
                    if (colorCount[oldColor] == 0)
                        colorCount.erase(oldColor);
                    
                    // Update ball's color.
                    ballColor[ball] = newColor;
                    // Increase the count for the new color.
                    colorCount[newColor]++;
                }
            } else {
                // If the ball was not colored before, color it now.
                ballColor[ball] = newColor;
                colorCount[newColor]++;
            }
            
            // The number of distinct colors is the size of colorCount.
            result.push_back(colorCount.size());
        }
        
        return result;
    }
};
