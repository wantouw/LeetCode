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
    int map[100000];
    void traverseTree(TreeNode* root, int level){
        if(!root) return;
        map[level]+=root->val;
        if(root->left) traverseTree(root->left, level+1);
        if(root->right) traverseTree(root->right, level+1);
        return;
    }
    TreeNode* findCousin(TreeNode* root, int level){
        if(!root) return nullptr;
        int left = 0, right = 0;
        if(root->left != nullptr){
            left = root->left->val;
        }
        if(root->right != nullptr){
            right = root->right->val;
        }
        if(root->left){
            root->left->val = map[level+1] - (left + right);
        }
        if(root->right){
            root->right->val = map[level+1] - (left + right);
        }
        if(root->left)
        root->left = findCousin(root->left, level+1);
        if(root->right)
        root->right = findCousin(root->right, level+1);
        return root;
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        int level = 0;
        traverseTree(root, level);
        root->val = 0;
        root = findCousin(root, level);
        return root;
    }
};