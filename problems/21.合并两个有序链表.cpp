/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)    return l2;
        if (!l2)    return l1;
        ListNode* h = new ListNode(0);
        ListNode* cur = h;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                // std::cout << "l1-val=" << l1->val << std::endl;
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            } else {
                // std::cout << "l2-val=" << l2->val << std::endl;
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }

        if (l1) {
            cur->next = l1;
        } else if (l2) {
            cur->next = l2;
        }
        return h->next;
    }
};
// @lc code=end

