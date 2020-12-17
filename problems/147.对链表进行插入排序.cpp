/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
 *
 * https://leetcode-cn.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (65.36%)
 * Likes:    230
 * Dislikes: 0
 * Total Accepted:    44.1K
 * Total Submissions: 67.4K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 对链表进行插入排序。
 * 
 * 
 * 插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
 * 每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
 * 
 * 
 * 
 * 插入排序算法：
 * 
 * 
 * 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
 * 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
 * 重复直到所有输入数据插入完为止。
 * 
 * 目前有个想法是：使用三个指针去处理，分别是前面的指针，当前的指针，以及下面一个指针
 * 使用当前指针进行比较，如果比较退出，那么使用上一个指针将目标元素插进来，不影响整体流程
 * 下一个指针的作用是保留下一个元素的指针索引，避免断链
 * 
 * 做指针类型的题目需要注意的是：1.不要断链，2.不要弄出环，3.注意空指针的问题
 * 
 * 
 * 示例 1：
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2：
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
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
    void print(ListNode* node, const std::string& word = "xxx") {
        cout << word << endl;
        ListNode* what = node;
        while (what) {
            cout << what->val << " ";
            what = what->next;
        }
        cout << endl;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode root;
        root.next = head;
        ListNode *cur = head, *pre = &root, *next = head->next;
        while (cur) {
            next = cur->next;   // 避免断链
            cur->next = nullptr;
            ListNode* new_cur = head;
            ListNode* new_pre = head;
            bool has_insert = false;
            while (new_cur) {
                // 第一个元素不需要插入，直接使用就可以
                if (new_cur == cur) {
                    has_insert = true;
                    break;
                }
                if (new_cur->val > cur->val) {
                    cur->next = new_cur->next;
                    new_cur->next = cur;
                    int v = cur->val;
                    cur->val = new_cur->val;
                    new_cur->val = v;
                    has_insert = true;
                    break;
                }
                new_pre = new_cur;
                new_cur = new_cur->next;
            }
            if (!has_insert) {
                new_pre->next = cur;
            }
            pre = cur;
            cur = next;
        }
        return root.next;
    }

    ListNode* insertionSortList_notgood(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode parent;
        parent.next = head;
        ListNode *pre = &parent, *cur = pre->next, *next = cur->next;
        int last_val = cur->val;
        while (cur) {
            // 找到不满足排序的数字
            pre = &parent;
            while (cur->next && last_val <= cur->next->val) {
                pre = cur;
                cur = cur->next;
            }
            last_val = cur->val;
            next = cur->next;
            pre->next = next;   // 摘除了当前节点，并且将后面的链表链接起来
            cout << "pre=" << pre->val << ", cur=" << cur->val;
            if (next) {
                cout << ", next=" << next->val;
            }
            cout << endl;
            // 将乱序的数字放到指定位置
            ListNode *tmp = head;
            while (tmp) {
                cout << tmp->val << " ";
                tmp = tmp->next;
            }
            cout << endl;
            tmp = head;
            while (tmp) {
                if (tmp->val < cur->val) {
                    tmp = tmp->next;
                } else {
                    cur->next = tmp->next;
                    tmp->next = cur;
                    int v = cur->val;
                    cur->val = tmp->val;
                    tmp->val = v;
                    tmp = head;
                    while (tmp) {
                        cout << tmp->val << ", ";
                        tmp = tmp->next;
                    }
                    cout << endl;
                    break;
                }
            }
            cur = next;

            tmp = head;
            while (tmp) {
                cout << tmp->val << " ";
                tmp = tmp->next;
            }
            cout << endl;
            cout << "pre=" << pre->val << ", cur=" << cur->val;
            if (next) {
                cout << ", next=" << next->val;
            }
            cout << endl;
            cout << "=============\n";
        }
        return parent.next;
    }

    ListNode* insertionSortList_old(ListNode* head) {
        ListNode parent;
        ListNode* cur = head;
        bool has_insert = false;
        while (cur) {
            ListNode* next = cur->next;
            ListNode* pcur = parent.next;
            while (pcur) {
                if (cur->val < pcur->val) {
                    cur->next = pcur->next;
                    pcur->next = cur;
                    int tmp = pcur->val;
                    pcur->val = cur->val;
                    cur->val = tmp;
                    break;
                }
                if (!pcur->next) {
                    cur->next = pcur->next;
                    pcur->next = cur;
                    break;   
                }
                pcur = pcur->next;
            }
            if (!has_insert) {
                cur->next = parent.next;
                parent.next = cur;
                has_insert = true;
            }
            cur = next;
        }
        return parent.next;
    }
};
// @lc code=end

class Solution {
public:
ListNode* insertionSortList(ListNode* head) {
	if (!head || !head->next)
		return head;
	ListNode *dummyhead = new ListNode(-1);//伪头指针
	dummyhead->next = head;
	ListNode *prev = head;
	ListNode *node = head->next;
	while (node)
	{
		if (node->val < prev->val)
		{
			ListNode* temp = dummyhead;//！！temp要等于dummyhead，这样才可以比较第一个元素
			while (temp->next->val < node->val)//！！！这里是temp->next：因为要修改前面的temp的指向
			{
				temp = temp->next;//指针后移
			}
			prev->next = node->next;
			node->next = temp->next;
			temp->next = node;
			node = prev->next;//此时不用改变prev指向！因为prev没有变，只是待排序元素变了位置。
		}
		else
		{
			prev = prev->next;
			node = node->next;
		}
	}
	return dummyhead->next;//!!!不能返回head！！因为后面会改变head所指向内存的位置！
}
};

