/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-17 21:57:28
 */
/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */
#include <vector>
#include <string>

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

    void binaryTreePaths(TreeNode* root, vector<int>& nums,
    vector<vector<int>>& ans){
        if(!root)   return;
        nums.emplace_back(root->val);
        if(!root->left && !root->right){
            ans.emplace_back(nums);
        }    
        binaryTreePaths(root->left,nums,ans);
        binaryTreePaths(root->right,nums,ans);
        nums.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string str;
        vector<string> res;
        vector<int> nums;
        vector<vector<int>> ans;
        binaryTreePaths(root,nums,ans);
        for(int i = 0 ; i < ans.size() ; i++){
            str.clear();
            str.append(to_string(ans[i][0])) ;
            for(int j = 1 ; j < ans[i].size() ; j++){
                str.append("->" + to_string(ans[i][j]));
            }
            res.emplace_back(str);
        }
        return res;
    }
};
// @lc code=end

