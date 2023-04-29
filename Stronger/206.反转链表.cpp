/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (72.49%)
 * Likes:    2185
 * Dislikes: 0
 * Total Accepted:    817.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,2]
 * 输出：[2,1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目范围是 [0, 5000]
 * -5000 
 * 
 * 
 * 
 * 
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 * 
 * 
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
public:
/**
 * @brief 反转链表，双指针法，真的方便
 * 
 * @param head 
 * @return ListNode* 
 */
    ListNode* reverseList0(ListNode* head) {
        ListNode* ptr = nullptr;            // 记录新的链表
        ListNode* cur = head;               // 记录要遍历的元素
        ListNode* next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = ptr;
            ptr = cur;
            cur = next;
        }
        return ptr;
    }
    ListNode* reverseList1(ListNode* head) {
        ListNode* ptr = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = ptr;
            ptr = cur;
            cur = next;
        }
        return ptr;
    }


    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* next = nullptr;       // 下一个
        ListNode* cur = head;           // 当前
        while (cur) {
            next = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = next;
        }

        return dummy->next;
    }
};
// @lc code=end

