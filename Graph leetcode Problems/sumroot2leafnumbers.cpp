// Sum root to leaf numbers

// Here we treat each root as leaf path in a binary tree as digits of number
//          then we return the sum of all those numbers

class Solution {
public:
    int sumNumbers(TreeNode* root){
        return sum(root, 0);
    }
    int sum(TreeNode* node, int sumNum){
        if (!node) {
            return 0;
        }
        sumNum = sumNum * 10 + node -> val;
        if (!node->left && !node->right) {
            return sumNum;
        }
        return sum(node->left, sumNum) + sum(node->right, sumNum);
    }
};