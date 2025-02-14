#include <vector>

class ProductOfNumbers {
private:
    std::vector<int> prefixProducts;
public:
    ProductOfNumbers() {
        prefixProducts = {1}; // Initialize with 1 for easier multiplication
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProducts = {1}; // Reset prefix product list when a zero appears
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    
    int getProduct(int k) {
        int size = prefixProducts.size();
        if (k >= size) {
            return 0; // A zero must have appeared, so product is zero
        }
        return prefixProducts.back() / prefixProducts[size - k - 1];
    }
};
