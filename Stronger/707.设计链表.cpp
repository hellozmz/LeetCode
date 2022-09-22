/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 *
 * https://leetcode.cn/problems/design-linked-list/description/
 *
 * algorithms
 * Medium (33.98%)
 * Likes:    564
 * Dislikes: 0
 * Total Accepted:    150.9K
 * Total Submissions: 445.2K
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n' +
  '[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next
 * 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
 * 
 * 在链表类中实现这些功能：
 * 
 * 
 * get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
 * addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
 * addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
 * addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index
 * 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
 * deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * MyLinkedList linkedList = new MyLinkedList();
 * linkedList.addAtHead(1);
 * linkedList.addAtTail(3);
 * linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
 * linkedList.get(1);            //返回2
 * linkedList.deleteAtIndex(1);  //现在链表是1-> 3
 * linkedList.get(1);            //返回3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 所有val值都在 [1, 1000] 之内。
 * 操作次数将在  [1, 1000] 之内。
 * 请不要使用内置的 LinkedList 库。
 * 
 * 
 */

// @lc code=start
class MyLinkedList {
struct Node {
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};
private:
    Node* dummyHead = nullptr;          // 虚拟头节点
    Node* tail = nullptr;               // 最后一个节点
    int len = 0;

public:
    MyLinkedList() {
        dummyHead = new Node(0);
        tail = dummyHead;
        len = 0;
    }
    
    int get(int index) {
        // 索引下标是 [0,len)
        if (index >= len || index < 0) {
            return -1;
        }
        Node* cur = dummyHead;
        while (index-- >= 0) {
            cur = cur->next;
        }
        // printNodes();
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = dummyHead->next;
        dummyHead->next = node;
        ++len;
        if (len == 1) {
            tail = node;
        }
        // printNodes();
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);
        tail->next = node;
        tail = node;
        ++len;
        // printNodes();
    }
    
    void addAtIndex(int index, int val) {
        if (index > len) {
            return;
        } else if (index < 0) {
            addAtHead(val);
        } else if (index == len) {
            addAtTail(val);
        } else {
            Node* cur = dummyHead;
            // 要找对索引前面一个的节点
            while (index-- > 0) {
                cur = cur->next;
            }
            Node* node = new Node(val);
            node->next = cur->next;
            cur->next = node;
            ++len;
        }
        // printNodes();
    }
    
    void deleteAtIndex(int index) {
        if (index >= len || index < 0) {
            return;
        } else if (index == 0) {
            Node* node = dummyHead->next;
            dummyHead->next = node->next;
            --len;
            delete node;
        } else {
            int tmp = index;
            Node* cur = dummyHead;
            while (index-- > 0) {
                cur = cur->next;
            }
            Node* toBeDelete = cur->next;
            cur->next = toBeDelete->next;
            if (tmp == len - 1) {
                tail = cur;
            }
            --len;
            delete toBeDelete;
        }
        // printNodes();
    }

    void printNodes() {
        Node* ptr = dummyHead->next;
        while (ptr != nullptr) {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

