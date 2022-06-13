/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
                /// 采用三指针法
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* tmp = head;
        ListNode* cur = head->next;
        while(cur->next){
            ListNode* nex = cur->next;
            cur->next = tmp;
            tmp = cur;
            cur = nex;
        }
        cur->next = tmp;
        return cur;
    }
};
// @lc code=end

