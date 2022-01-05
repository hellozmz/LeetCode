/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 *
 * https://leetcode-cn.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (51.64%)
 * Likes:    513
 * Dislikes: 0
 * Total Accepted:    68.7K
 * Total Submissions: 133K
 * Testcase Example:  '8\n[4,1,8,4,5]\n[5,0,1,8,4,5]\n2\n3'
 *
 * 编写一个程序，找到两个单链表相交的起始节点。
 * 
 * 如下面的两个链表：
 * 
 * 
 * 
 * 在节点 c1 开始相交。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2,
 * skipB = 3
 * 输出：Reference of the node with value = 8
 * 输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为
 * [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB
 * = 1
 * 输出：Reference of the node with value = 2
 * 输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为
 * [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
 * 输出：null
 * 输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为
 * 0，而 skipA 和 skipB 可以是任意值。
 * 解释：这两个链表不相交，因此返回 null。
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 如果两个链表没有交点，返回 null.
 * 在返回结果后，两个链表仍须保持原有的结构。
 * 可假定整个链表结构中没有循环。
 * 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
 * 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA, *ptrB = headB;
        bool firstA = true, firstB = true;
        while (ptrA && ptrB) {
            if (ptrA == ptrB) {
                return ptrA;
            }
            ptrA = ptrA->next;
            ptrB = ptrB->next;
            if (!ptrA && firstA) {
                ptrA = headB;
                firstA = false;
            }
            if (!ptrB && firstB) {
                ptrB = headA;
                firstB = false;
            }
        }
        return nullptr;
    }

    ListNode *getIntersectionNode_old1(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *ptrA = headA, *ptrB = headB;
        while (ptrA) {
            ptrA = ptrA->next;
            ++lenA;
        }
        while (ptrB) {
            ptrB = ptrB->next;
            ++lenB;
        }
        if (lenB > lenA) {
            return getIntersectionNode(headB, headA);
        }

        int sub = lenA - lenB;
        ptrA = headA;
        ptrB = headB;
        while (sub--) {
            ptrA = ptrA->next;
        }

        while (ptrA != ptrB) {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }

        return ptrA;
    }


    ListNode *getIntersectionNode_old(ListNode *headA, ListNode *headB) {
        int len_a = 0, len_b = 0;
        ListNode* cur_a = headA;
        ListNode* cur_b = headB;
        while (cur_a) {
            ++len_a;
            cur_a = cur_a->next;
        }
        while (cur_b) {
            ++len_b;
            cur_b = cur_b->next;
        }
        if (len_a==0 || len_b==0) {
            return nullptr;
        }
        ListNode* long_list = headA;
        ListNode* short_list = headA;
        if (len_a < len_b) {
            long_list = headB;
        } else {
            short_list = headB;
        }
        int diff = std::fabs(len_a - len_b);
        // if (diff == 0) {
        //     return nullptr;
        // }
        // std::cout << "len_a=" << len_a << std::endl;
        // std::cout << "len_b=" << len_b << std::endl;
        // std::cout << "diff=" << diff << std::endl;
        while (diff > 0) {
            long_list = long_list->next;
            --diff;
        }
        while (long_list != short_list) {
            long_list = long_list->next;
            short_list = short_list->next;
        }
        return long_list;
    }
};
// @lc code=end

