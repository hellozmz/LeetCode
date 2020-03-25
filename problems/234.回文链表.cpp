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
 * 找到中间的数字，然后翻转后半部分的数据
 * 找到中间的节点使用快慢指针
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
        if (!head || !head->next) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        // printNode(head);
        // printNode(slow);    // left
        // printNode(right);
        auto right = slow->next;
        while (right) {
            // printNode(head);
            // printNode(right);
            if (head->val != right->val) {
                // cur_ptr->next = reverse(cur_ptr->next);
                return false;
            }
            head = head->next;
            right = right->next;
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

