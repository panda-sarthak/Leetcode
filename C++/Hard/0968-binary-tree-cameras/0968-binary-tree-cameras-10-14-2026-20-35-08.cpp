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
    enum class NODE_STATE{
        I_AM_COVERED_BUT_NO_CAM = 1,
        I_HAVE_CAM = 2,
        NOT_COVERED = 3
    };
    int total_cam;
    NODE_STATE dfs(TreeNode* root){
        if(root==nullptr) return NODE_STATE::I_AM_COVERED_BUT_NO_CAM;
        NODE_STATE sl=dfs(root->left);
        NODE_STATE sr=dfs(root->right);
        if(sl==NODE_STATE::NOT_COVERED||sr==NODE_STATE::NOT_COVERED){//1st priority check
            total_cam++;
            return NODE_STATE::I_HAVE_CAM;
        }
        if(sl==NODE_STATE::I_HAVE_CAM||sr==NODE_STATE::I_HAVE_CAM){//2nd priority check
            return NODE_STATE::I_AM_COVERED_BUT_NO_CAM;
        }
        return NODE_STATE::NOT_COVERED;
    }
    int minCameraCover(TreeNode* root) {
        total_cam=0;
        NODE_STATE s=dfs(root);
        if(s==NODE_STATE::NOT_COVERED) total_cam++;
        return total_cam;
    }
};