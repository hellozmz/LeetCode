/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 * 1.估计两个数字都是正整数，没有小数、负数、科学计数法等
 * 2.注意进位的问题
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h = new ListNode(-1);
        ListNode* cur = h;
        int carry = 0;  // 1代表进位，0代表不进位
        while (l1 && l2) {
            int num1 = l1->val;
            int num2 = l2->val;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            cout << "carry=" << carry << ", sum=" << sum << endl;
            ListNode* tmp = new ListNode(sum%10);
            cur->next = tmp;
            l1 = l1->next;
            l2 = l2->next;
            cur = cur->next;
        }

        if (l2) {
            l1 = l2;
        }
        while (l1) {
            int num1 = l1->val;
            int sum = num1 + carry;
            carry = sum / 10;
            cout << "carry=" << carry << ", sum=" << sum << endl;
            ListNode* tmp = new ListNode(sum%10);
            cur->next = tmp;
            l1 = l1->next;
            cur = cur->next;
        }

        if (0 != carry) {
            ListNode* tmp = new ListNode(carry);
            cur->next = tmp;
            cur = cur->next;
        }
        return h->next;
    }
};
// @lc code=end

