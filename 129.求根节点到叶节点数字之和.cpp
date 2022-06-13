/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-16 21:19:59
 */
/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    void pathnums(TreeNode* root, vector<vector<int>>& ans , vector<int>& nums){

        if(!root){
            return;
        }
        nums.emplace_back(root->val);
        if(!root->left && !root->right){
            ans.emplace_back(nums);
        }
        pathnums(root->left,ans,nums);
        pathnums(root->right,ans,nums);
        nums.pop_back();
    }

    int sumNumbers(TreeNode* root) {     
        int sum = 0;
        vector<vector<int>> ans ;
        vector<int> nums;
        pathnums(root,ans,nums);
        for(auto ptr : ans){
            int res = 0;
            for(auto i : ptr){
                res = res * 10 + i;
            }
            sum += res;
        }
        return sum;
    }
};
// @lc code=end

