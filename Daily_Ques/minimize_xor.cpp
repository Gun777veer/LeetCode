#include <iostream>
#include <bitset>

int minimizeXor(int num1, int num2) {
    int setBitsNum2 = __builtin_popcount(num2);  // Count set bits in num2
    int result = 0;
    
    // Step 1: Set bits of result starting from most significant bits of num1
    for (int i = 31; i >= 0 && setBitsNum2 > 0; --i) {
        if (num1 & (1 << i)) {  // Check if bit i is set in num1
            result |= (1 << i);  // Set the corresponding bit in result
            --setBitsNum2;       // Decrease the required set bits count
        }
    }
    
    // Step 2: If there are still set bits needed, set them in least significant positions
    for (int i = 0; i <= 31 && setBitsNum2 > 0; ++i) {
        if ((result & (1 << i)) == 0) {  // Check if bit i is not already set in result
            result |= (1 << i);          // Set the bit in result
            --setBitsNum2;               // Decrease the required set bits count
        }
    }
    
    return result;
}

int main() {
    int num1 = 3, num2 = 5;
    std::cout << "Output: " << minimizeXor(num1, num2) << std::endl;

    num1 = 1, num2 = 12;
    std::cout << "Output: " << minimizeXor(num1, num2) << std::endl;

    return 0;
}
