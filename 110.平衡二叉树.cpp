/*
 * @Description: 主要判断左右子树高度差是否大于1
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-14 16:29:10
 */
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */
#include <algorithm>
#include <iostream>
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
    int getheight(TreeNode* root){
        if(!root )  return 0;
        return max(getheight(root->left), getheight(root->right)) + 1; 
    }

    bool check(TreeNode* root){
        if(!root)   return true;
        if(getheight(root->left) - getheight(root->right) > 1 || getheight(root->left) - getheight(root->right) < -1)
            return false;
        return check(root->left) & check(root->right);
    }

    bool isBalanced(TreeNode* root) {
        return check(root);
    }
};
// @lc code=end

