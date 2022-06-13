/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-25 19:53:47
 */
/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */
#include <queue>

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
    

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(!root)           return sum;
        queue<TreeNode*> tqu;
        tqu.push(root);
        while(!tqu.empty()){
            TreeNode* cur = tqu.front();
            tqu.pop();
            if(cur->left)   tqu.push(cur->left);
            if(cur->right)  tqu.push(cur->right);
            if(cur->left != nullptr && !cur->left->left && !cur->left->right){
                sum += cur->left->val;
            }
        }
        return sum;
    }
};
// @lc code=end

