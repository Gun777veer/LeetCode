#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);
        
        // Left-to-right pass
        int operations = 0, balls = 0;
        for (int i = 0; i < n; i++) {
            answer[i] += operations;
            if (boxes[i] == '1') {
                balls++;  // Count the current ball
            }
            operations += balls;  // Increment operations by the number of balls
        }
        
        // Right-to-left pass
        operations = 0, balls = 0;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] += operations;
            if (boxes[i] == '1') {
                balls++;  // Count the current ball
            }
            operations += balls;  // Increment operations by the number of balls
        }
        
        return answer;
    }
};

int main() {
    Solution sol;
    string boxes = "110";
    vector<int> result = sol.minOperations(boxes);
    
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;  // Output: 1 1 3
    
    boxes = "001011";
    result = sol.minOperations(boxes);
    
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;  // Output: 11 8 5 4 3 4
    
    return 0;
}
