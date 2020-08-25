/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (63.34%)
 * Likes:    385
 * Dislikes: 0
 * Total Accepted:    37.8K
 * Total Submissions: 59.6K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 * 
 * 示例 1:
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2:
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
 * 
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
    ListNode* cut(ListNode* head, int size) {
        auto p = head;
        // 先多处理一个，最后处理到链表的末尾，而不是下一个
        while (--size && p) {
            p = p->next;
        }
        if (!p) {
            return p;
        }
        auto next = p->next;
        p->next = nullptr;
        // std::cout << "head=" << head->val << ", next=" << (next ? next->val : 0) << std::endl;
        return next;
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (left && right) {
            if (left->val <= right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if (left) {
            cur->next = left;
        } else {
            cur->next = right;
        }
        // std::cout << "end=" << dummy.next->val << std::endl;
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        int len = 0;
        ListNode dummy(0);
        dummy.next = head;
        auto cur = head;
        while (cur) {
            ++len;
            cur = cur->next;
        }
        // std::cout << len << std::endl;

        for (int i = 1; i < len; i <<= 1) {
            cur = dummy.next;
            auto tail = &dummy;
            while (cur) {
                auto left = cur;
                auto right = cut(left, i);
                cur = cut(right, i);
                // std::cout << "left=" << left->val
                //         << ", right=" << right->val
                //         << ", next=" << (cur ? cur->val : 0) << std::endl;

                tail->next = merge(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }

        return dummy.next;
    }
};
// @lc code=end

