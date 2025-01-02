#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// Function to check if a word starts and ends with a vowel
bool isVowelWord(const string& word) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    return vowels.count(word.front()) && vowels.count(word.back());
}

vector<int> vowelStrings(const vector<string>& words, const vector<vector<int>>& queries) {
    int n = words.size();
    vector<int> isVowel(n, 0);
    
    // Step 1: Precompute whether each word is a vowel word
    for (int i = 0; i < n; ++i) {
        isVowel[i] = isVowelWord(words[i]);
    }
    
    // Step 2: Build prefix sum array
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + isVowel[i];
    }
    
    // Step 3: Answer the queries
    vector<int> ans;
    for (const auto& query : queries) {
        int li = query[0], ri = query[1];
        ans.push_back(prefixSum[ri + 1] - prefixSum[li]);
    }
    
    return ans;
}

int main() {
    // Example 1
    vector<string> words1 = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries1 = {{0, 2}, {1, 4}, {1, 1}};
    vector<int> result1 = vowelStrings(words1, queries1);
    for (int res : result1) {
        cout << res << " ";
    }
    cout << endl;

    // Example 2
    vector<string> words2 = {"a", "e", "i"};
    vector<vector<int>> queries2 = {{0, 2}, {0, 1}, {2, 2}};
    vector<int> result2 = vowelStrings(words2, queries2);
    for (int res : result2) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
