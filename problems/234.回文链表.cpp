/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (39.94%)
 * Likes:    382
 * Dislikes: 0
 * Total Accepted:    58.2K
 * Total Submissions: 145.8K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
    bool isPalindrome(ListNode* head) {
        int len = 0;
        auto cur_ptr = head;
        while (cur_ptr) {
            cur_ptr = cur_ptr->next;
            ++len;
        }
        if (len == 1 || len == 0) {
            return true;
        }
        int mid = len / 2;
        cur_ptr = head;
        while (--mid > 0) {
            cur_ptr = cur_ptr->next;
        }
        // printNode(head);
        // printNode(cur_ptr->next);
        if (len%2) cur_ptr = cur_ptr->next;
        cur_ptr->next = reverse(cur_ptr->next);
        // printNode(head);
        auto tmp_head_ptr = cur_ptr->next;
        while (tmp_head_ptr) {
            // printNode(head);
            // printNode(tmp_head_ptr);
            if (head->val != tmp_head_ptr->val) {
                // cur_ptr->next = reverse(cur_ptr->next);
                return false;
            }
            head = head->next;
            tmp_head_ptr = tmp_head_ptr->next;
        }
        // cur_ptr->next = reverse(cur_ptr->next);
        return true;
    }

    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        auto head_ptr = head->next;     // 子链的头
        auto tmp_ptr = head_ptr;
        head->next = nullptr;
        while (head_ptr) {
            tmp_ptr = head_ptr;
            head_ptr = tmp_ptr->next;
            tmp_ptr->next = head;
            head = tmp_ptr;
        }
        // printNode(head);
        return head;
    }

    void printNode(ListNode* head) {
        while (head) {
            std::cout << head->val << "->";
            head = head->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};
// @lc code=end

