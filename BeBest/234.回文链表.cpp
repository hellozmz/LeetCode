/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    // 使用快慢指针，最终返回中间的位置或者后半部分的第一个位置
    ListNode *findMid(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 使用头插法
    ListNode *reverse(ListNode *head) {
        ListNode node;
        ListNode *ptr = head;

        while (head != nullptr) {
            ptr = ptr->next;
            head->next = node.next;
            node.next = head;
            head = ptr;
        }
        // printList(node.next);
        return node.next;
    }

    // 是否存在diff
    bool diff(ListNode *left, ListNode *right) {
        while (left != nullptr && right != nullptr) {
            if (left->val != right->val) {
                return true;
            }
            left = left->next;
            right = right->next;
        }
        return false;
    }
    
    void printList(ListNode *ptr) {
        while (ptr != nullptr) {
            std::cout << ptr->val << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }

    bool isPalindrome(ListNode* head) {
        // 学习了一个新思路，将链表拆分开，然后对后半部分的链表进行反转，这样就可以使用两个指针遍历，比较结果
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode *mid = findMid(head);
        ListNode *right = reverse(mid);
        bool result = !diff(head, right);
        return result;
    }
};
// @lc code=end

