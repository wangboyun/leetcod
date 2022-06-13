/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-10-26 20:21:04
 */
/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

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
    

    /* 找到当前节点位置 */
    TreeNode* serach_bst(TreeNode* root, int key){
        if(root == nullptr)
            return nullptr;
        if(root->val == key)
            return root;
        else if(key > root->val)
            return serach_bst(root->right, key);
        else
            return serach_bst(root->left, key);
    }

    /* 找到当前节点的父节点 */
    TreeNode* getParentNode(TreeNode* root, TreeNode * child , int& flag){
        
        static TreeNode* parent = nullptr;
        if(root)
        {
            if(root->left == child) {
                parent = root;
                flag = 0;           // 左孩子
            }

            if(root->right == child ){
                parent =  root;
                flag = 1;          // 右孩子
            }
               
            getParentNode(root->left, child, flag);
            getParentNode(root->right, child, flag);
        }
        return parent;

    }

    TreeNode*  get_hearld_bst(TreeNode* cur){
        TreeNode* q = cur->left;
        if(q->right == nullptr)
            return q;
        TreeNode* p = q->right;
        while(p->right)
            p = p->right;
        return p;

    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* cur = serach_bst(root , key);      // 当前需要删除的节点
        TreeNode* parent = nullptr;                // 其双亲节点
        int flag = 0;                               // 0 -- 左 ， 1 -- 右
        if(!cur)
            return root;
        
        // 情况1 ( 删除的节点为叶子节点 )
        if(cur->left == nullptr && cur->right == nullptr){
            delete cur;
            cur = nullptr;
        }

        // 情况2 ( 该节点只有左节点 或 只有右节点 )
        // 有左子树情况
        else if(cur->left != nullptr && cur->right == nullptr){ 
            parent = getParentNode(root, cur , flag);
            if(!flag)
                parent->left = cur->left ;
            else
                parent->right = cur->left ;
            delete cur;
            cur = nullptr;
        }
        // 有右子树
        else if (cur->left == nullptr && cur->right != nullptr) {
            parent = getParentNode(root, cur , flag);
            if(!flag)
                parent->left = cur->right ;
            else
                parent->right = cur->right ;
            delete cur;
            cur = nullptr;
        }
        // 情况3 (该节点即有左节点又有右节点)
        else {
            // 方法是 以要删除的节点cur 的先驱节点(按中序遍历结果来看)herald 代替cur ， 在调用
            TreeNode* hearld = get_hearld_bst(cur);
            int data = hearld->val;
            deleteNode(root , hearld->val);
            cur->val = data;       // 形式上的删除, 将先驱节点数据赋给要删除的节点cur
        }
        return root;
    } 
    
};
// @lc code=end

