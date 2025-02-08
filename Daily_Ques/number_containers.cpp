#include <unordered_map>
#include <map>

class NumberContainers {
private:
    std::unordered_map<int, int> indexToNumber; // Maps index to the number stored at that index
    std::unordered_map<int, std::map<int, bool>> numberToIndices; // Maps number to a sorted map of indices

public:
    NumberContainers() {}

    void change(int index, int number) {
        if (indexToNumber.find(index) != indexToNumber.end()) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) {
                numberToIndices.erase(oldNumber);
            }
        }
        
        indexToNumber[index] = number;
        numberToIndices[number][index] = true;
    }

    int find(int number) {
        if (numberToIndices.find(number) != numberToIndices.end() && !numberToIndices[number].empty()) {
            return numberToIndices[number].begin()->first;
        }
        return -1;
    }
};
