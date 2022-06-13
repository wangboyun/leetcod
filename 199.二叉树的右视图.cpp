/*
 * @Description: 广度优先搜索，找到每层的最后一个元素
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-17 19:05:49
 */
/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */
#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> tq;
        if(!root)
            return ans;
        tq.emplace(root);
        while(!tq.empty()){
            int size = tq.size();
            for(int i = 0 ; i < size ; i++){
                TreeNode* front = tq.front();
                tq.pop();
                if(front->left)
                    tq.emplace(front->left);
                if(front->right)
                    tq.emplace(front->right);
                if(i == size -1){
                    ans.emplace_back(front->val);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

