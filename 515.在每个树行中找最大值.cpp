/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-10-26 21:21:38
 */
/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */

#include <vector>
#include <queue>
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> que;
        
        if(!root)
            return ans;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            set<int> set;
            set.clear();
            for(int i = 0 ; i < size ; i++){
                TreeNode* frist = que.front();
                que.pop();
                if(frist->left){
                    que.push(frist->left);
                }
                if(frist->right){
                    que.push(frist->right);
                }
                set.insert(frist->val);
            }
            ans.emplace_back(*set.rbegin());
        }
        return ans;
    }
};
// @lc code=end

