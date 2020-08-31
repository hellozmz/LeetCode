/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (45.07%)
 * Likes:    385
 * Dislikes: 0
 * Total Accepted:    30.4K
 * Total Submissions: 67.4K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
 * 
 * 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
 * 写入数据 put(key, value) -
 * 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。
 * 
 * 进阶:
 * 
 * 你是否可以在 O(1) 时间复杂度内完成这两种操作？
 * 
 * 示例:
 * 
 * LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回  1
 * cache.put(3, 3);    // 该操作会使得密钥 2 作废
 * cache.get(2);       // 返回 -1 (未找到)
 * cache.put(4, 4);    // 该操作会使得密钥 1 作废
 * cache.get(1);       // 返回 -1 (未找到)
 * cache.get(3);       // 返回  3
 * cache.get(4);       // 返回  4
 * 
 * 
 */

// @lc code=start

class DLNode {
 public:
    int key, value;
    DLNode* pre = nullptr;
    DLNode* next = nullptr;

 public:
    DLNode(int key, int value) {
        // std::cout << "DLNode=" << value << std::endl;
        this->key = key;
        this->value = value;
    }
    DLNode() {
        // 注意构造函数之间调用的关系
        new (this)DLNode(0, 0);
    }
    void UpdateValue(int key, int value) {
        this->key = key;
        this->value = value;
    }
};


// 主要就是双向链表，实现LRU的功能
class LRUCache {
 private:
    const int capacity_ = 0;
    std::unordered_map<int, DLNode*> cache_;
    DLNode* head_ = nullptr;    // 为了避免边界上的指针问题，使用伪节点
    DLNode* tail_ = nullptr;

 public:
    explicit LRUCache(int capacity) : capacity_(capacity){
        head_ = new DLNode();
        tail_ = new DLNode();
        head_->next = tail_;
        tail_->pre = head_;
    }
    
    int get(int key) {
        // printDL("before get.");
        // std::cout << "get=" << key << std::endl;
        if (cache_.count(key) <= 0) {
            return -1;
        }
        DLNode* ptr = cache_[key];
        moveToHead(ptr);
        // printDL("after get.");
        // printDL("after get(unorder).", false);
        return ptr->value;
    }
    
    void put(int key, int value) {
        // printDL("before put.");
        // std::cout << "put=" << value << std::endl;
        if (cache_.count(key) <= 0) {
            // cache中找不到
            if (static_cast<int>(cache_.size()) >= capacity_) {
                cache_.erase(tail_->pre->key);
                removeTail();
            }
            DLNode* ptr = new DLNode(key, value);
            addToHead(ptr);
            cache_[key] = ptr;
        } else {
            // cache中可以找到
            DLNode* ptr = cache_[key];
            if (ptr->value != value) {
                ptr->UpdateValue(key, value);
            }
            moveToHead(ptr);
        }
        // printDL("after put.");
        // printDL("after put(unorder).", false);
    }

 private:
    void addToHead(DLNode* ptr) {
        ptr->next = head_->next;
        head_->next->pre = ptr;
        head_->next = ptr;
        ptr->pre = head_;
    }

    // 注意空指针问题
    void moveToHead(DLNode* ptr) {
        // 摘
        ptr->pre->next = ptr->next;
        ptr->next->pre = ptr->pre;
        // 插
        ptr->next = head_->next;
        head_->next->pre = ptr;
        ptr->pre = head_;
        head_->next = ptr;
    }

    void removeTail() {
        // printDL("before removeTail.");
        auto cur = tail_->pre;
        // std::cout << "removeTail=" << cur->value << std::endl;
        // printDL("after removeTail00000.");
        // if (cur == nullptr)  return;
        cur->pre->next = tail_;

        // printDL("after removeTail0.");
        tail_->pre = cur->pre;

        // printDL("after removeTail1.");
        delete cur;
        // printDL("after removeTail.");
    }

    void printDL(const std::string& fname, bool order = true) {
        std::cout << "=================" << std::endl;
        std::cout << fname << std::endl;
        auto tmp = head_;
        if (!order) {
            tmp = tail_;
        }
        while (tmp) {
            std::cout << tmp->value << "   ";

            if (order) {
                tmp = tmp->next;
            } else {
                tmp = tmp->pre;
            }
        }
        std::cout << std::endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
