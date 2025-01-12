#include <iostream>
#include <string>
using namespace std;

bool canBeValid(string s, string locked) {
    int n = s.length();
    if (n % 2 != 0) 
        return false;  // Odd-length strings can't be valid

    // Left-to-right pass
    int openCount = 0, flexibleCount = 0;
    for (int i = 0; i < n; ++i) {
        if (locked[i] == '1') {
            if (s[i] == '(') 
                openCount++;
            else 
                openCount--;
        } else {
            flexibleCount++;
        }
        if (openCount + flexibleCount < 0) 
            return false;  // Too many ')'
    }

    // Right-to-left pass
    int closeCount = 0;
    flexibleCount = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (locked[i] == '1') {
            if (s[i] == ')') 
                closeCount++;
            else 
                closeCount--;
        } else {
            flexibleCount++;
        }
        if (closeCount + flexibleCount < 0) 
            return false;  // Too many '('
    }

    return true;
}

int main() {
    // Test cases
    string s1 = "))()))", locked1 = "010100";
    cout << (canBeValid(s1, locked1) ? "true" : "false") << endl;

    string s2 = "()()", locked2 = "0000";
    cout << (canBeValid(s2, locked2) ? "true" : "false") << endl;

    string s3 = ")", locked3 = "0";
    cout << (canBeValid(s3, locked3) ? "true" : "false") << endl;

    return 0;
}
