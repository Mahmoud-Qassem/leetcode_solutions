class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postIndex;
        for (int i = 0; i < postorder.size(); i++)
            postIndex[postorder[i]] = i;

        int preIndex = 0;
        return buildTree(preorder, postorder, postIndex, preIndex, 0, postorder.size() - 1);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, unordered_map<int, int>& postIndex,
                        int& preIndex, int left, int right) {
        if (preIndex >= preorder.size() || left > right)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        if (left == right) return root;  // Leaf node, return immediately

        int leftSubtreeRoot = preorder[preIndex];
        int postLeftIdx = postIndex[leftSubtreeRoot];

        root->left = buildTree(preorder, postorder, postIndex, preIndex, left, postLeftIdx);
        root->right = buildTree(preorder, postorder, postIndex, preIndex, postLeftIdx + 1, right - 1);

        return root;
    }
};