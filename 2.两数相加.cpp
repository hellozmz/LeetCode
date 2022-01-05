/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* result = new ListNode();
        ListNode *p = result;
        int up = 0;
        while (h1 != nullptr && h2 != nullptr) {
            int value = (h1->val + h2->val + up) % 10;
            up = (h1->val + h2->val + up) / 10;
            ListNode *tmp = new ListNode(value);
            p->next = tmp;
            p = p->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        while (h1 != nullptr) {
            int value = (h1->val + up) % 10;
            up = (h1->val + up) / 10;
            ListNode *tmp = new ListNode(value);
            p->next = tmp;
            p = p->next;
            h1 = h1->next;
        }
        while (h2 != nullptr) {
            int value = (h2->val + up) % 10;
            up = (h2->val + up) / 10;
            ListNode *tmp = new ListNode(value);
            p->next = tmp;
            p = p->next;
            h2 = h2->next;
        }
        if (up > 0) {
            ListNode *tmp = new ListNode(up);
            p->next = tmp;
        }
        return result->next;
    }
};
// @lc code=end

