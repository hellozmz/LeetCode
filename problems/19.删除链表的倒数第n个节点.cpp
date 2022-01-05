/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (37.23%)
 * Likes:    670
 * Dislikes: 0
 * Total Accepted:    114.1K
 * Total Submissions: 306.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
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
    ListNode* removeNthFromEnd_old(ListNode* head, int n) {
        ListNode* dumb = new ListNode(-1, head);
        ListNode* first = head;
        ListNode* second = dumb;
        while (--n > 0) {
            first = first->next;
        }

        // std::cout << first->val << std::endl;
        // 停在要删除节点的前一个位置
        while (first->next) {
            first = first->next;
            second = second->next;
        }
        // std::cout << second->val << std::endl;
        if (second->next)
            second->next = second->next->next;
        return dumb->next;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dumb, *first, *second;
        dumb.next = head;
        first = dumb.next;
        second = &dumb;
        while (n-- > 0) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        if (second && second->next) {
            second->next = second->next->next;
        }
        return dumb.next;
    }

};
// @lc code=end

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 新增头指针 方便操作（如可删除头节点）
        ListNode* newHead = new ListNode(-1,head);
        ListNode*p = newHead;
        ListNode*q = newHead;
        for(int i=0;i<n;i++){
            q=q->next;
        }
        while(q->next){
            q=q->next;
            p=p->next;
        }
        //for(q;(q->next)!=nullptr;q=q->next,p=p->next){}

        // 删除结点
        p->next = p->next->next;
        return newHead->next;
    }
};
