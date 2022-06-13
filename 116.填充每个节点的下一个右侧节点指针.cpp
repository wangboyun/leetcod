/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-16 20:06:43
 */
/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    //思路层次遍历
    Node* connect(Node* root) {
        queue<Node*> tq;
        if(!root)
            return nullptr;
        tq.emplace(root);
        while(!tq.empty()){
            int size = tq.size();
            Node* front = nullptr;
            for(int i = 0 ; i < size ; i++){ 
                front = tq.front();
                tq.pop();
                if(front->left)
                    tq.emplace(front->left);
                if(front->right)
                    tq.emplace(front->right);
                    
            } 
            for(int i = 0 ; i < tq.size() ; i++){
                Node* temp = tq.front();
                tq.pop();
                temp->next = tq.front();
                tq.emplace(temp);
            }
            if(front)
                front->next = nullptr;
        }
        return root;
    }
};
// @lc code=end

