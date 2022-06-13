/*
 * @Description: 二叉搜索树的中序遍历是一个递增数组
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-10-28 16:44:09
 */
/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

#include <vector>
#include <set>
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
    void inorder(TreeNode* root , vector<int>& ve){
        if(!root)
            return;
        inorder(root->left, ve);
        ve.emplace_back(root->val);
        inorder(root->right, ve);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> ve;
        set<int> set;
        inorder(root, ve);
        for(int i = 1 ; i < ve.size() ; ++i){
            set.insert(ve[i] - ve[i-1]);
        }
        return *set.begin();
    }
};
// @lc code=end

