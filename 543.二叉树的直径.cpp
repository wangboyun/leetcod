/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-10-28 16:54:11
 */
/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */


#include <algorithm>
#include <set>
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
    int height(TreeNode* root){
        if(!root)
            return 0;
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        return std::max(leftheight , rightheight) + 1;
    }

    void diameterOfBinaryTree(TreeNode* root , std::set<int>& set){
        if(!root)
            return ;
        set.insert(height(root->left) + height(root->right));
        diameterOfBinaryTree(root->left , set);
        diameterOfBinaryTree(root->right , set);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        /// set是一个从小到大排列的数据，最大值在末尾。
        std::set<int> set;

        if(!root)
            return 0;
        diameterOfBinaryTree(root , set);
        return *set.rbegin();
    }
};
// @lc code=end

