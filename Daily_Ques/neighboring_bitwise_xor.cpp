#include <iostream>
#include <vector>

using namespace std;

int main() {
    Solution solution;
    
    vector<int> derived1 = {1, 1, 0};
    cout << solution.doesValidArrayExist(derived1) << endl; // Output: 1 (true)

    vector<int> derived2 = {1, 1};
    cout << solution.doesValidArrayExist(derived2) << endl; // Output: 1 (true)

    vector<int> derived3 = {1, 0};
    cout << solution.doesValidArrayExist(derived3) << endl; // Output: 0 (false)

    return 0;
}
