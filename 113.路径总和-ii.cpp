/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-14 19:50:53
 */
/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void pathSum(TreeNode* root, int targetSum , 
                vector<vector<int>>& ans , vector<int>& nums){

        if(!root){
            return;
        }
        nums.emplace_back(root->val);
        if(!root->left && !root->right && root->val == targetSum){
            ans.emplace_back(nums);
        }
        pathSum(root->left,targetSum-root->val,ans,nums);
        pathSum(root->right,targetSum-root->val,ans,nums);
        nums.pop_back();
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> nums;
        pathSum(root,targetSum,ans,nums);
        return ans;
    }
};
// @lc code=end

