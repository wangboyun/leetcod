/*
 * @Description: 先利用bfs 拿到每层的数据
    在利用栈把奇数次下标的数组反转
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-14 14:56:37
 */
/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

#include <vector>
#include <queue>
#include <stack>

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
    void LevelOrder(TreeNode* root , vector<vector<int>>& ans){
        queue<TreeNode*> tq;
        if(!root)
            return ;
        tq.emplace(root);
        while(!tq.empty()){
            int size = tq.size();
            vector<int> temp ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* front = tq.front();
                tq.pop();
                if(front->left)
                    tq.emplace(front->left);
                if(front->right)
                    tq.emplace(front->right);
                temp.emplace_back(front->val);
            }
            ans.emplace_back(temp);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans ;
        stack<int> st;
        LevelOrder(root,ans);
        for(int i = 1 ; i < ans.size() ; i += 2){
            for(int j = 0 ; j < ans[i].size() ; j++){
                st.push(ans[i][j]);
            }
            ans[i].clear();
            while(!st.empty()){
               ans[i].emplace_back(st.top());
               st.pop();
            }
        }
        return ans;
    }
};
// @lc code=end

