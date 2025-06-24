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

    bool compare(TreeNode* one, TreeNode* two){
        if(one == NULL && two == NULL) return true;
        if(one == NULL || two == NULL) return false;

        if(one->val != two->val) return false;

        return compare(one->left, two->left) && compare(one->right, two->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root == NULL && subRoot == NULL) return true;
        if(root == NULL || subRoot == NULL) return false;

        if(root->val == subRoot->val) if(compare(root, subRoot)) return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
