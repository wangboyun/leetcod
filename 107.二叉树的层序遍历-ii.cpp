/*
 * @Description: 利用bfs 得到的每层数据,每次都头插在 二维数组中
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-14 15:32:56
 */
/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */
#include <queue>
#include <stack>
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
    void levelOrder(TreeNode* root , vector<vector<int>>& ans){
        if(!root)
            return;
        queue<TreeNode*> tq;
        tq.emplace(root);
        while(!tq.empty()){
            int size = tq.size();
            vector<int> temp;
            for(int i = 0; i < size ; i++){
                TreeNode* front = tq.front();
                tq.pop();
                if(front->left)
                    tq.emplace(front->left);
                if(front->right)
                    tq.emplace(front->right);
                temp.emplace_back(front->val);
            }
            ans.emplace(ans.begin(),temp);
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root ,ans);
        return ans;
    }
};
// @lc code=end

