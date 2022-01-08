/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (66.63%)
 * Likes:    1427
 * Dislikes: 0
 * Total Accepted:    234.9K
 * Total Submissions: 352.6K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
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
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 * 
 * 
 * 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
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
    ListNode* sortList(ListNode* head) {
        // 使用归并的算法比较简单（自顶向下，不过不是最省资源的，自底向上是最省资源的形式）
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        return sort(head, nullptr);
    }

    ListNode *sort(ListNode *head, ListNode *end) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == end) {
            head->next = nullptr;
            return head;
        }
        ListNode *mid = head;
        ListNode *fast = head, *slow = head;
        while (fast != end) {
            slow = slow->next;
            fast = fast->next;
            if (fast != end) {
                fast = fast->next;
            }
        }
        mid = slow;
        
        return merge(sort(head, mid), sort(mid, end));
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *ptr = head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }

        if (l1 != nullptr) {
            ptr->next = l1;
        } else if (l2 != nullptr) {
            ptr->next = l2;
        }

        return head->next;
    }
};
// @lc code=end

