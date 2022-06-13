/*
 * @Description: 二叉搜索树前序遍历是一个升序数组
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-17 20:28:40
 */
/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    void preorder(TreeNode* root , vector<int>&nums){
        if(!root)   return;
        preorder(root->left, nums);
        nums.emplace_back(root->val);
        preorder(root->right, nums);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        preorder(root, nums);
        return nums.at(k-1);
    }
};
// @lc code=end

