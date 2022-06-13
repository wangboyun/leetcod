/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-08-27 21:16:58
 */
/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

#include <cstdlib>
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
    void inorder(TreeNode* root,vector<int>& nums){
        if(!root)
            return ;
        inorder(root->left,nums);
        nums.emplace_back(root->val);
        inorder(root->right, nums);
    }

    TreeNode* search(const int val ,TreeNode* root ){
        if(root == nullptr){
            return nullptr;
        }
        
        if(val == root->val){
           return root;
        }
        TreeNode* se = search(val , root->left );
        TreeNode* s = search(val , root->right );   
        if(se)
            return se;
        if(s)
            return s;
        return nullptr;
    }

    void recoverTree(TreeNode* root) {
        // 主要工作就是找到两个错误节点 二叉搜索树中序遍历是一个有序数组
        vector<int> nums;
        inorder(root,nums);
        // 从nums这个无序数组中找出错误交换的两个节点
        int swap_one, swap_two = -1; int j = 0;
        for(int i = 0 ; i < nums.size()-1 ; i++){
            if(nums[i] > nums[i+1]){
                swap_one = i;
                break;
            }
        }
        for(j = swap_one+1; j < nums.size()-1 ; j++){
            if(nums[j] > nums[j+1]){
                swap_two = j+1;
                break;
            }
        }
        if(j == nums.size()-1)
            swap_two = swap_one+1;
        
        // 找到树中这两节点的指针，交换这两个节点的数据即可
        TreeNode* one = nullptr; TreeNode* two = nullptr; 
        one = search(nums[swap_one], root);
        two = search(nums[swap_two], root);

        if(one && two){
            int temp = two->val;
            two->val = one->val;
            one->val = temp;
        }
    }
};
// @lc code=end

