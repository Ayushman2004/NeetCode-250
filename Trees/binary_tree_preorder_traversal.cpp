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

    void pot(TreeNode* root, vector<int>& vec){

        if(root == NULL) return;

        vec.push_back(root->val);
        pot(root->left, vec);
        pot(root->right, vec);
    }

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> vec;
        pot(root, vec);

        return vec;        
    }
};
