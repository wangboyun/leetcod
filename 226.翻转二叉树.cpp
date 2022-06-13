/*
 * @Description: 按照右根左方向遍历
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-17 19:31:29
 */
/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
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
    void swapTree(TreeNode* root){
        if(!root)
            return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = right;
        root->right = left;
        swapTree(root->left);
        swapTree(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        swapTree(root);
        return root;
    }
};
// @lc code=end

