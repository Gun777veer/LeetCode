#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";
        stack<int> st;
        int num = 1; // Start from the smallest digit (1 to 9)

        for (int i = 0; i <= pattern.size(); i++) {
            st.push(num++);  // Always push the next available number

            // When we reach 'I' or the end, pop the stack to construct the result
            if (i == pattern.size() || pattern[i] == 'I') {
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }
        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    cout << sol.smallestNumber("IIIDIDDD") << endl;  // Output: "123549876"
    cout << sol.smallestNumber("DDD") << endl;      // Output: "4321"
    return 0;
}
