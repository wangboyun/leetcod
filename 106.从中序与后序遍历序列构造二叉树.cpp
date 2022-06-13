/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-08 21:09:26
 */
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    void creatTree(vector<int>& inorder, vector<int>& postorder,
    int in_left , int in_right , int po_left, int po_right, TreeNode* root) {
        root->val = postorder[po_right];
        root->left = new TreeNode;
        root->right = new TreeNode;
        int m = in_left;
        while(inorder[m] != postorder[po_right])
            m++;
        if(m == in_left){
            //无左子树
            root->left = nullptr;
        }
        else {
            // 左子树
            creatTree(inorder,postorder,in_left,m-1,po_left,po_left+m-1-in_left,root->left);
        }
        if(m == in_right){
            // 无右子树
            root->right = nullptr;
        }
        else {
            creatTree(inorder,postorder,m+1,in_right,po_right-in_right+m,po_right-1,root->right);
        }
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode;
        int pleft = 0;
        int pright = postorder.size() - 1;
        int inleft = 0;
        int inright = inorder.size() - 1;
        creatTree(inorder,postorder,inleft,inright,pleft,pright,root);
        return root;
    }
};
// @lc code=end

