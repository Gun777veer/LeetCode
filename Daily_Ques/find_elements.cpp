#include <iostream>
#include <unordered_set>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class FindElements {
private:
    std::unordered_set<int> values;  // Stores recovered values

public:
    FindElements(TreeNode* root) {
        if (root) {
            root->val = 0;  // Start with root value 0
            recoverTree(root);
        }
    }
    
    void recoverTree(TreeNode* node) {
        if (!node) return;
        
        values.insert(node->val);  // Store the recovered value
        
        if (node->left) {
            node->left->val = 2 * node->val + 1;
            recoverTree(node->left);
        }
        
        if (node->right) {
            node->right->val = 2 * node->val + 2;
            recoverTree(node->right);
        }
    }

    bool find(int target) {
        return values.count(target);  // O(1) lookup
    }
};

int main() {
    TreeNode* root = new TreeNode(-1);
    root->right = new TreeNode(-1);

    FindElements findElements(root);
    std::cout << std::boolalpha;  // Print `true` or `false`
    std::cout << "Find 1: " << findElements.find(1) << std::endl;  // false
    std::cout << "Find 2: " << findElements.find(2) << std::endl;  // true

    return 0;
}
