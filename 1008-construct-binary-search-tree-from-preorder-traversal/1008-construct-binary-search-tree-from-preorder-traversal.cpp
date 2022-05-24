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
class Solution {
public:
    TreeNode* solve(vector<int> preorder, int &i, int start, int end, int n){
        if(i == n || preorder[i] > end || preorder[i] < start) return NULL;

        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root -> left = solve(preorder,i,start,root -> val,n);
        root -> right = solve(preorder,i,root -> val,end,n);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        
        int i = 0;
        return solve(preorder,i,INT_MIN,INT_MAX,n);
    }
};