/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-12 16:48:07
 */
/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    TreeNode* bstinsert(const int val,TreeNode* root){
        if(!root){
            TreeNode* node = new TreeNode{val,nullptr,nullptr};
            root = node;
        }
        if(val > root->val){
            root->right = bstinsert(val,root->right);
        }
        else if (val < root->val) {
            root->left = bstinsert(val, root->left);
        }
        return root;
    }

    void dfs(vector<int>& nums,vector<vector<int>>& allkind,int n,int step, vector<int>& visited){
        if(step == n){
            allkind.push_back(nums);
            return ;
        }

        for(int i = 0 ; i < n ; i++){
            if(visited[i] == 0){
                nums[step] = i + 1;
                visited[i] = 1;
                dfs(nums, allkind,n,step+1,visited);
                visited[i] = 0;
            } 
        }
        return ;
    }


    bool compare(TreeNode* node , TreeNode* root){
        if(node == nullptr && root == nullptr)
            return true;
        else if(node == nullptr || root == nullptr)
            return false;
        if(node->val != root->val)
            return false;
        return compare(node->left, root->left) & compare(node->right, root->right);
    }

    // 判断ans中是否包含root
    bool ans_contain(vector<TreeNode*>& ans,TreeNode* root){
        for(int i = 0 ; i < ans.size() ; i++){
            if(compare(ans[i],root))
                return true;
        }
        return false;
    }

    vector<TreeNode*> generateTrees(int n) {
        // 1、求[1,n]有都少种排列方法 深度优先算法dfs
        vector<int> nums(n,0);
        vector<vector<int>> allkind;
        vector<int> visited(n,0);
        vector<TreeNode*> ans;
        TreeNode* root = nullptr;
        
        dfs(nums,allkind,n,0,visited);

        // 2、 将数组建成树
        int size = allkind[0].size();
        for(int i = 0 ; i < size ; i++){
            root = bstinsert(allkind[0][i], root);
        }
        ans.push_back(root);

        for(int i = 1 ; i < allkind.size() ; i++){
            TreeNode* root = nullptr;
            for(int j = 0 ; j < size ; j++){
                root = bstinsert(allkind[i][j], root);
            }
            // 剔除重复的树
            if(!ans_contain(ans,root)){
                ans.push_back(root);
            }
        }
        return ans;
    }
};
// @lc code=end

