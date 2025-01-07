#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        int n = words.size();
        
        // Compare each pair of strings
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break;  // No need to check further once found
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> words1 = {"mass", "as", "hero", "superhero"};
    vector<string> result1 = sol.stringMatching(words1);
    
    for (string& word : result1) {
        cout << word << " ";
    }
    cout << endl;  // Output: "as hero"

    vector<string> words2 = {"leetcode", "et", "code"};
    vector<string> result2 = sol.stringMatching(words2);
    
    for (string& word : result2) {
        cout << word << " ";
    }
    cout << endl;  // Output: "et code"

    vector<string> words3 = {"blue", "green", "bu"};
    vector<string> result3 = sol.stringMatching(words3);
    
    for (string& word : result3) {
        cout << word << " ";
    }
    cout << endl;  // Output: ""
    
    return 0;
}
