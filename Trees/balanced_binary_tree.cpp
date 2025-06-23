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

    int help(TreeNode* root, bool& flag){
        if(root == NULL) return 0;

        int left = help(root->left, flag);
        int right = help(root->right, flag);

        if(abs(left-right)>1) flag = false;

        return 1+max(left,right);
    }

    bool isBalanced(TreeNode* root) {

        bool flag = true;
        help(root, flag);
        
        return flag;
    }
};
