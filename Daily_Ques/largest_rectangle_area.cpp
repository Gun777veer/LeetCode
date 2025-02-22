#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    heights.push_back(0); // Add a zero-height bar to process all elements

    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }
    
    return maxArea;
}

int main() {
    vector<int> heights1 = {2,1,5,6,2,3};
    cout << "Largest Rectangle Area: " << largestRectangleArea(heights1) << endl;

    vector<int> heights2 = {2,4};
    cout << "Largest Rectangle Area: " << largestRectangleArea(heights2) << endl;
    
    return 0;
}
