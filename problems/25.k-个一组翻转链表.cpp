/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (63.28%)
 * Likes:    781
 * Dislikes: 0
 * Total Accepted:    112.3K
 * Total Submissions: 176.9K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
 * 指针题目太可怕了，各种边界问题
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
    // 将从head 到 tail中间的数据翻转位置，head和tail分别代表起始和终止
    std::pair<ListNode*, ListNode*> reserve(ListNode* head, ListNode* tail) {
        ListNode parent;
        parent.next = head;
        ListNode* cur = head;
        ListNode* next = tail->next;
        // cout << "head=" << head->val << ", tail=" << tail->val << ", next=" << next->val << endl;
        while (true) {
            ListNode *tmp = cur->next;
            cur->next = parent.next;
            parent.next = cur;
            // cout << "==> head=" << parent.next->val << ", tail=" << head->val << endl;
            if (tmp == next) {
                // cout << "* head=" << parent.next->val << ", tail=" << head->val << endl;
                return {parent.next, head};
            }
            cur = tmp;
        }
        return {parent.next, nullptr};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode parent;
        parent.next = head;
        ListNode *cur = &parent;
        while (cur->next) {
            ListNode *h = cur->next;

            int count = 0;
            ListNode* tail = cur;
            while (count++  < k) {
                tail = tail->next;
                if(!tail) {
                    return parent.next;
                }
            }
            ListNode* next = tail->next;
            auto rtn = reserve(h, tail);
            rtn.second->next = next;
            cur->next = rtn.first;
            cur = rtn.second;

            // auto x = &parent;
            // while (x) {
            //     cout << x->val << " ";
            //     x = x->next;
            // }
            // cout << endl;
        }
        return parent.next;
    }


    ListNode* reverseKGroup_old(ListNode* head, int k) {
        ListNode parent;
        parent.next = head;
        ListNode* cur = &parent;
        while (cur) {
            ListNode *tmp = cur;
            vector<ListNode*> nodes(k);
            for (int i = 0; i < k; ++i) {
                tmp = tmp->next;
                nodes[i] = tmp;
                if (!tmp) {
                    return parent.next;
                }
            }
            for (int i = 0; i < k - 1; ++i) {
                nodes[i]->next = nodes[k-1]->next;
                nodes[k-1]->next = nodes[i];
            }
            cur->next = nodes[k-1];
            cur = nodes[0];

            // auto t = &parent;
            // while (t) {
            //     cout << t->val << " ";
            //     t = t->next;
            // }
            // cout << endl;
        }
        return parent.next;
    }
};
// @lc code=end

