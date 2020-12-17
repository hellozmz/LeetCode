/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (67.69%)
 * Likes:    728
 * Dislikes: 0
 * Total Accepted:    190.8K
 * Total Submissions: 279.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4]
 * 输出：[2,1,4,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [1]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 100] 内
 * 0 
 * 
 * 链表的题目，遍历的节点一次走两个步子，然后将接下来两个节点的顺序进行调整，最终实现整体调整完毕
 * 迭代的思路真不错。链表的题目还要好好总结
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
    ListNode* swapPairs(ListNode* head) {
        ListNode parent;
        parent.next = head;
        ListNode *tmp = &parent;
        while (tmp->next && tmp->next->next) {
            ListNode *node1 = tmp->next, *node2 = tmp->next->next;
            node1->next = node2->next;
            node2->next = node1;
            tmp->next = node2;
            tmp = node1;
        }
        return parent.next;
    }
};
// @lc code=end

