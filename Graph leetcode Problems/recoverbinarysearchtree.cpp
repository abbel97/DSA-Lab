// Recovery Binary Search Tree

// Here two nodes in BFS were swapped by mistake, from that we identify and swap them back
//              to restore in-order property

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* ab = nullptr;
        TreeNode* begin = nullptr;
        TreeNode* next = nullptr;
        function <void(TreeNode*root)> 
        dfs = [&](TreeNode* root) {
        if (!root) {
            return;
        }
        dfs(root->left);
        if (ab && ab->val > root->val) {
        if (!begin) begin = ab;
        next = root;
        }
        ab = root;
        dfs(root->right);
        };
        dfs(root);
        swap(begin->val, next->val);

    }
};