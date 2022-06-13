/*
 * @Description: 将有序数组 构建成一个平衡二叉树 (AVL)
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-14 15:46:34
 */
/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */
#include <algorithm>
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
    int getheight(TreeNode* root){
        if(!root)   return 0;
        return max(getheight(root->left) , getheight(root->right)) + 1;
    }

    TreeNode* RR_rotating(TreeNode* root){
        TreeNode* q = root;
        TreeNode* val = root->right->left;
        root = root->right;
        root->left = q;
        q->right = val;
        return root;
    }

    TreeNode* LL_rotating(TreeNode* root){
        TreeNode* q = root;
        TreeNode* val = root->left->right;
        root = root->left;
        root->right = q;
        q->left = val;
        return root;
    }

    TreeNode* RL_rotating(TreeNode* root){
        root->right = LL_rotating(root->right);
        return RR_rotating(root);
    }
    TreeNode* LR_rotating(TreeNode* root){
        root->left = RR_rotating(root->left);
        return LL_rotating(root);
    }

    TreeNode* insert_avl(const int val , TreeNode* root){
        if(!root){
            TreeNode* node = new TreeNode {val ,nullptr ,nullptr};
            root = node;
        }
        if(val > root->val){
            // 右边插入 
            root->right = insert_avl(val , root->right);
            // 对应不平衡树的旋转为 RR , RL
            if(getheight(root->right) - getheight(root->left) == 2){
                if(val > root->right->val){
                    root = RR_rotating(root);
                }
                else 
                    root = RL_rotating(root);
            }
        }
        if(val < root->val){
            // 左边插入
            root->left = insert_avl(val , root->left);
            // 对应不平衡树的旋转为 LL , LR
            if(getheight(root->left) - getheight(root->right) == 2){
                if(val > root->left->val){
                    root = LR_rotating(root);
                }
                else 
                    root = LL_rotating(root);
            }
        }
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        for(int i = 0 ; i < nums.size() ; i++){
            root = insert_avl(nums[i] , root);
        }
        return root;
    }
};
// @lc code=end

