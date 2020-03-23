/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (66.62%)
 * Likes:    747
 * Dislikes: 0
 * Total Accepted:    148.7K
 * Total Submissions: 223K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 * 
 * 相比于头插法，递归更难理解。
 * 递归的时候，先要将返回条件判断清楚
 * 然后调用自己开始递归，获取到head后面的节点都是逆序的
 * 接下来是重点：
 * 让头和接下来的一个元素和后面的相交换，此时，head代表最后一个元素。
 * 返回上次递归的返回结果，就是头节点
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
    ListNode* reverseList1(ListNode* head) {
        ListNode* rtn = nullptr;
        ListNode* h_ptr = head;
        ListNode* r_ptr = rtn;
        while (head) {
            head = h_ptr->next;
            h_ptr->next = r_ptr;
            r_ptr = h_ptr;
            h_ptr = head;
        }
        return r_ptr;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* next = head->next;
        if (!head || !next) {
            return head;
        }
        ListNode* ptr = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ptr;
    }
};
// @lc code=end

