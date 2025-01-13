#include <iostream>
#include <stack>
#include <string>

using namespace std;

int minFinalLength(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            // Remove the pair by popping the stack
            st.pop();
        } else {
            // Add the current character to the stack
            st.push(c);
        }
    }
    // The size of the stack is the minimum achievable length
    return st.size();
}

int main() {
    string s1 = "abaacbcbb";
    cout << "Output: " << minFinalLength(s1) << endl; // Output: 5
    
    string s2 = "aa";
    cout << "Output: " << minFinalLength(s2) << endl; // Output: 2
    
    return 0;
}
