/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-17 21:58:34
 */
/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    vector<int> robtree(TreeNode* root){
        if(root == nullptr)
            return vector<int>{0,0};
        vector<int> left = robtree(root->left);
        vector<int> right = robtree(root->right);
        int val1 = root->val + left[0] + right[0];
        int val2 = max(left[0],left[1]) + max(right[0] , right[1]);
        return {val2 , val1};
    }

    int rob(TreeNode* root) {
        vector<int> res = robtree(root);    
        return max(res[0] , res[1]);    
    }
};
// @lc code=end

