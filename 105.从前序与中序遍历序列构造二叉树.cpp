/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-07 20:42:11
 */
/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    void creatTree(vector<int>& preorder, vector<int>& inorder,
    int pleft, int pright, int inleft , int inright,TreeNode* root){
        root->val = preorder[pleft];
        root->left = new TreeNode;
        root->right = new TreeNode;
        int m = inleft;
        while(preorder[pleft] != inorder[m])
            m++;
        if(m == inleft)
            root->left = nullptr;
        else
            creatTree(preorder,inorder, pleft+1 , pleft + m - inleft +1,
            inleft , m - 1, root->left);
        
        if(m == inright)
            root->right = nullptr;
        else
            creatTree(preorder,inorder, pleft + m - inleft +1 , pright,
            m + 1, inright, root->right);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode;
        int pleft = 0;
        int pright = preorder.size() - 1;
        int inleft = 0;
        int inright = inorder.size() - 1;
        creatTree(preorder,inorder,pleft,pright,inleft,inright,root);
        return root;
    }
};
// @lc code=end

