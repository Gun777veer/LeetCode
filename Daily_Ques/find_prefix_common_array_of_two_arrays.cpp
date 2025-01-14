#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> prefixCommonArray(const std::vector<int>& A, const std::vector<int>& B) {
    int n = A.size();
    std::vector<int> C(n, 0);
    std::unordered_set<int> seenA, seenB;
    int commonCount = 0;

    for (int i = 0; i < n; ++i) {
        seenA.insert(A[i]);
        seenB.insert(B[i]);

        if (seenA.count(B[i])) {
            ++commonCount;
        }
        if (seenB.count(A[i]) && A[i] != B[i]) {
            ++commonCount;
        }

        C[i] = commonCount;
    }

    return C;
}

int main() {
    std::vector<int> A = {1, 3, 2, 4};
    std::vector<int> B = {3, 1, 2, 4};
    
    std::vector<int> result = prefixCommonArray(A, B);
    
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
