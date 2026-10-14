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
    pair<int,int> dfs(TreeNode* root){
        if(root==nullptr) return {0,0};
        auto [l0,l1]=dfs(root->left);
        auto [r0,r1]=dfs(root->right);
        int c0=max(l0,l1)+max(r0,r1);
        int c1=root->val+l0+r0;
        return {c0,c1};
    }
    int rob(TreeNode* root) {
        auto [l0,l1]=dfs(root);
        return max(l0,l1);
    }
};