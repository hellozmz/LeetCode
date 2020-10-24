/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (48.56%)
 * Likes:    472
 * Dislikes: 0
 * Total Accepted:    69.5K
 * Total Submissions: 143.1K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            // cout << "nullptr" << endl;
            return nullptr;
        } else if (lists.size() == 1) {
            // cout << "list 0" << endl;
            return lists[0];
        }
        ListNode head, *tail = &head;
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        std::priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> queue(cmp);
        for (auto& node : lists) {
            if (node)
                queue.push(node);
        }
        while (!queue.empty()) {
            auto front = queue.top();
            // cout << front->val << endl;
            queue.pop();
            tail->next = front;
            tail = tail->next;
            if (front && front->next) {
                queue.push(front->next);
            }
        }

        return head.next;
    }
};
// @lc code=end
