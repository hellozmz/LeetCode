/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode.cn/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (51.95%)
 * Likes:    1462
 * Dislikes: 0
 * Total Accepted:    478.3K
 * Total Submissions: 916.2K
 * Testcase Example:  '[1,2,2,1]'
 *
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,2,1]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目在范围[1, 10^5] 内
 * 0 <= Node.val <= 9
 * 
 * 
 * 
 * 
 * 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 * 
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
    // 基本想法：
    // 先遍历一遍，获取长度，然后将链表从中间切开
    // 对后面的链表进行头插法逆序
    // 比较两个链表
public:
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode* ptr = head;
        while (ptr) {
            ++len;
            ptr = ptr->next;
        }

        ListNode* first = head;
        ListNode* second = head;
        int mid = (len + 1) / 2;
        while (mid > 0) {
            second = second->next;
            --mid;
        }

        second = nixu(second);
        return diff(first, second);
    }

    ListNode* nixu(ListNode* p) {
        ListNode node = ListNode(-1);
        ListNode* ptr = p;
        while (ptr) {
            ListNode* t = ptr;
            ptr = ptr->next;
            t->next = node.next;
            node.next = t;
        }
        return node.next;
    } 

    bool diff(ListNode* a, ListNode* b) {
        ListNode* p1 = a, *p2 = b;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};
// @lc code=end

