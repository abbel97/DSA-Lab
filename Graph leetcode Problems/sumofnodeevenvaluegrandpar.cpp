class Solution {
public:
  
    void children(TreeNode* ch , TreeNode* father , TreeNode* grandparent,int& sum){
        if(!ch){
            return ;
        }
        if(grandparent and grandparent -> val%2 == 0){
            sum += ch->val;
        }
        children(ch -> left , ch , father ,sum);
        children(ch -> right , ch , father ,sum);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int sum =0;
        children(root, NULL, NULL, sum);
        return sum;
    }
};