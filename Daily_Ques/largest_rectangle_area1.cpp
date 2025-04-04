#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        heights.insert(heights.begin(), 0);     // Add sentinel at the beginning
        heights.push_back(0);                   // Add sentinel at the end
        n = heights.size();

        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = i - st.top() - 1;   // Width between current and previous lower height
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};
