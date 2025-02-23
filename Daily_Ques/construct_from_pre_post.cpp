
class Solution {
public:
    unordered_map<int, int> postIndexMap; // Stores index of elements in postorder
    int preIndex = 0;

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder, int left, int right) {
        if (preIndex >= preorder.size() || left > right) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        if (left == right) return root; // Leaf node
        
        int leftSubtreeRootIndex = postIndexMap[preorder[preIndex]];
        
        root->left = constructFromPrePost(preorder, postorder, left, leftSubtreeRootIndex);
        root->right = constructFromPrePost(preorder, postorder, leftSubtreeRootIndex + 1, right - 1);
        
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = postorder.size();
        for (int i = 0; i < n; ++i) {
            postIndexMap[postorder[i]] = i;
        }
        return constructFromPrePost(preorder, postorder, 0, n - 1);
    }
};

// Helper function to print inorder traversal of the tree
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}
