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
    string solve(TreeNode* root, unordered_map<string,int> &cnts, vector<TreeNode*> &ans){
        if(root == NULL) return "$";
        if(root -> left == NULL && root -> right == NULL){
            string str = "$" + to_string(root -> val);
            if(cnts[str] == 1) ans.push_back(root);
            cnts[str]++;
            return str;
        }

        string left = solve(root -> left,cnts,ans);
        string right = solve(root -> right,cnts,ans);

        string str = to_string(root -> val) + left + right;
        if(cnts[str] == 1) ans.push_back(root);
        cnts[str]++;

        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> cnts;
        vector<TreeNode*> ans;

        solve(root,cnts,ans);

        return ans;
    }
};