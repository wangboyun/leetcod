/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-17 20:36:37
 */
/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// @lc code=start
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(p->val == root->val || q->val == root->val)
            return root;
        else if(p->val < root->val && q->val > root->val)
            return root;
        else if(p->val > root->val && q->val < root->val)
            return root;
        else if (p->val < root->val && q->val < root->val) {
            root = lowestCommonAncestor(root->left,p,q);
        }
        else {
            root = lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};
// @lc code=end

