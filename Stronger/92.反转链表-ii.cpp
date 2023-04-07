/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode.cn/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (55.67%)
 * Likes:    1539
 * Dislikes: 0
 * Total Accepted:    386.1K
 * Total Submissions: 693.9K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left  。请你反转从位置 left 到位置 right 的链表节点，返回
 * 反转后的链表 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目为 n
 * 1 
 * -500 
 * 1 
 * 
 * 
 * 
 * 
 * 进阶： 你可以使用一趟扫描完成反转吗？
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
    ListNode* reverseBetween(ListNode* head, int begin, int end) {
        if (!head || begin < 0 || end < 0) {
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* h1 = dummy;
        ListNode* h2 = dummy;
        // 获取新的头前面一个位置
        while (begin-- > 1) {
            h1 = h1->next;
        }
        // 获取尾部指针
        while (end-- > 0) {
            h2 = h2->next;
        }

        // 尾后一个
        ListNode* tail = h2->next;
        // 头前一个位置
        ListNode* newhead = h1;
        // 头
        // h1 = h1->next;
        cout << "h=" << h1->val << endl;
        cout << "e=" << tail->val << endl;

        ListNode* tmp = h1;
        while (h1 != tail) {
            tmp = h1->next;
            h1->next = newhead->next;
            newhead->next = h1;
            h1 = tmp;
        }

        ListNode* p = dummy->next;
        cout << "head->";
        while (p) {
            cout << p->val << "->";
            p = p->next;
        }
        cout << "null";


        return dummy->next;

    }
};
// @lc code=end

