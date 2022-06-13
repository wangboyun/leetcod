/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-14 20:22:56
 */
/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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

    void perorder(TreeNode* root , vector<int>& nums){
        if(!root)
            return;
        nums.emplace_back(root->val);
        perorder(root->left, nums); 
        perorder(root->right, nums);
    }

    void flatten(TreeNode* root) {
        vector<int> nums;
        perorder(root,nums);
        TreeNode* temp = root;
        TreeNode* pre = nullptr;
        for(int i = 0 ; i < nums.size() ; i++){
            if(temp){
                temp->val = nums.at(i);
                temp->left = nullptr;
                pre = temp;
                temp = temp->right;
            }
            else {
                TreeNode* node = new TreeNode{nums.at(i),nullptr,nullptr};
                pre->right = node;
                pre = node;
                temp = pre->right;
            }   
        }
    }
};
// @lc code=end

