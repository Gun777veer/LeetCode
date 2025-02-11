#include <iostream>
#include <string>

std::string removeOccurrences(std::string s, std::string part) {
    size_t pos;
    while ((pos = s.find(part)) != std::string::npos) {  // Find the leftmost occurrence
        s.erase(pos, part.length());  // Remove it
    }
    return s;
}

int main() {
    std::string s1 = "daabcbaabcbc", part1 = "abc";
    std::cout << removeOccurrences(s1, part1) << std::endl; // Output: "dab"

    std::string s2 = "axxxxyyyyb", part2 = "xy";
    std::cout << removeOccurrences(s2, part2) << std::endl; // Output: "ab"

    return 0;
}
