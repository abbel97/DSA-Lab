// All nnodes in distance k binary tree

//From the given binart tree and target node, we list all nodes that are exactly k nodges away

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>vec;
        queue<TreeNode*>q;
        unordered_map<int, TreeNode*>par;
        q.push(root);

        while(!q.empty()){
            int a = q.size();
            for(int i = 0; i < a; i++){
                auto top = q.front();
                q.pop();

                if(top -> left){
                    par[top -> left ->val] = top;
                    q.push(top -> left);
                }
                if(top -> right){
                    par[top -> right -> val] = top;
                    q.push(top ->right);
                }
            }
        }
        unordered_map<int, int>visited;
        q.push(target);
        while(k-- && !q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto top= q.front();
                q.pop();

                visited[top -> val] = 1;
                if(top->left && !visited[top->left->val]){
                    q.push(top -> left);
                }
                if(top->right && !visited[top -> right -> val]){
                    q.push(top -> right);
                }
                if(par[top->val] && !visited[par[top -> val] -> val]){
                    q.push(par[top -> val]);
                }
            }
        }
        while(!q.empty()){
            vec.push_back(q.front() -> val);
            q.pop();
        }
        return vec;
    }
};