#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (isdigit(c)) {
                if (!st.empty()) {
                    st.pop();  // Remove the closest non-digit character
                }
            } else {
                st.push(c);  // Push letters onto the stack
            }
        }
        
        // Construct the result string
        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.clearDigits("cb34") << endl;  // Output: ""
    cout << sol.clearDigits("abc123") << endl;  // Output: ""
    cout << sol.clearDigits("a1b2c3") << endl;  // Output: ""
    cout << sol.clearDigits("hello2world4") << endl;  // Output: "hellwrld"
    return 0;
}
