/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    unordered_map<int,bool>mp;

    FindElements(TreeNode* root) {
        mp.clear();
        rec(root);
    }
    void rec(TreeNode* root) {
        if(root == NULL )return ;

        if(root->val == -1)root->val=0;

        int value=root->val;
        mp[value]=true;

        if(root->left != NULL){
            root->left->val=2*value+1;
        }
        if(root->right!=NULL){
            root->right->val=2*value+2;
        }
        rec(root->left);
        rec(root->right);
    }
    
    bool find(int target) {
        return mp[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */