/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (63.89%)
 * Likes:    186
 * Dislikes: 0
 * Total Accepted:    21.8K
 * Total Submissions: 34K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 * 
 * 示例:
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // 返回 true
 * trie.search("app");     // 返回 false
 * trie.startsWith("app"); // 返回 true
 * trie.insert("app");   
 * trie.search("app");     // 返回 true
 * 
 * 说明:
 * 
 * 
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串。
 * 
 * 
 */

// @lc code=start

// 只记录一个节点
class TrieNode {
 public:
    TrieNode() {
        child_list_ = std::vector<TrieNode*>(26, nullptr);
    }
    bool IsEnd() {
        return is_end_;
    }
    void SetWordEnd() {
        is_end_ = true;
    }
    void SetNextNode(char c, TrieNode* node) {
        child_list_[c - 'a'] = node;
    }
    TrieNode* GetNextNode(char c) {
        return child_list_[c - 'a'];
    }

 private:
    std::vector<TrieNode*> child_list_/* (26, nullptr) */;
    bool is_end_ = false;    // 代表是字符串的终点，即有该单词
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root_ = new TrieNode();
    }

    ~Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto* cur = root_;
        // std::cout << "insert " << word << std::endl;
        for (auto ch : word) {
            if (cur->GetNextNode(ch) == nullptr) {
                cur->SetNextNode(ch, new TrieNode());
                // std::cout << "ch=" << ch << std::endl;
            }
            cur = cur->GetNextNode(ch);
        }
        cur->SetWordEnd();
        // std::cout << "IsEnd=" << cur->IsEnd() << std::endl;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto* cur = root_;
        // std::cout << "search " << word << std::endl;
        for (auto ch : word) {
            if (cur->GetNextNode(ch) != nullptr) {
                // std::cout << "ch=" << ch << std::endl;
                cur = cur->GetNextNode(ch);
            } else {
                return false;
            }
        }
        // std::cout << "IsEnd=" << cur->IsEnd() << std::endl;
        return cur->IsEnd();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto* cur = root_;
        for (auto ch : prefix) {
            if (cur->GetNextNode(ch) != nullptr) {
                cur = cur->GetNextNode(ch);
            } else {
                return false;
            }
        }
        // std::cout << "IsEnd=" << cur->IsEnd() << std::endl;
        return true;
    }
 private:
    TrieNode* root_ = nullptr;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

