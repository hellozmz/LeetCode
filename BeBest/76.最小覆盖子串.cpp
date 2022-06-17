/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (42.99%)
 * Likes:    1519
 * Dislikes: 0
 * Total Accepted:    213.4K
 * Total Submissions: 495.8K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
 * 。
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 和 t 由英文字母组成
 * 
 * 
 * 
 * 进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        // 使用滑动窗口
        int left = 0, right = 0;    // 滑动窗口左闭右开区间
        int len = INT_MAX;          // 记录返回结果总长度
        int start = left;           // 记录返回结果的起始位置
        std::unordered_map<char, int> /* 记录s字符串中满足条件的元素以及个数 */windows, /* 记录t字符串中需要的元素以及个数*/ need;
        for (const auto ch : t) {
            ++need[ch];
        }
        int count = 0;              // 记录匹配上的个数，最终返回结果的条件是：count == need.size()
        while (right < s.size()) {
            char ch = s[right];
            ++right;                                // 更新成闭区间
            if (need.count(ch) > 0) {               // 更新滑动窗口中元素（只记录有用的元素，没有用的元素不记录）
                ++windows[ch];
                if (windows[ch] == need[ch]) {
                    ++count;
                }
            }

            // 当已经能够正确获取所有元素的时候，滑动左窗口（收缩）
            while (need.size() == count) {
                // 更新返回结果（获取最小的子串）
                if (len > right - left) {
                    start = left;
                    len = right - left;
                }
                char ch = s[left];
                ++left;                                 // 真正更新左边界的动作
                if (need.count(ch) > 0) {
                    if (windows[ch] == need[ch]) {
                        --count;
                    }
                    --windows[ch];
                }
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
    string minWindow0(string s, string t) {
        // 先使用暴力算法解决
        if (s.size() < t.size()) {
            return "";
        }
        int s_size = s.size();
        int t_size = t.size();
        std::map<char, int> t_map;              // 存储t中各个元素，以及元素个数
        for (int i = 0; i < t_size; ++i) {
            ++t_map[t[i]];
        }
        std::string result = s + s;
        std::string tmp_result = result;
        for (int begin = 0; begin < s_size; ++begin) {
            // std::map<char, int> tmp_t_map = t_map;
            // std::cout << "epoch\n";
            // for (const auto &k_v : tmp_t_map) {
            //     std::cout << "key = " << k_v.first << ", value = " << k_v.second << std::endl;
            // }
            for (int end = begin + t_size; end <= s_size; ++end) {
                std::map<char, int> tmp_t_map = t_map;
                for (int i = begin; i < end; ++i) {
                    if (tmp_t_map.count(s[i]) > 0) {
                        // std::cout << "delete = " << s[i] << std::endl;
                        --tmp_t_map[s[i]];
                        // for (const auto &kv : tmp_t_map) {
                        //     std::cout << kv.first << ", " << kv.second << std::endl;
                        // }
                        if (tmp_t_map[s[i]] == 0) {
                            tmp_t_map.erase(s[i]);
                        }
                        if (tmp_t_map.size() == 0) {
                            if (tmp_result.size() > (end - begin)) {
                                tmp_result = s.substr(begin, end - begin);
                            }
                        }
                    }
                }
                // std::cout << "begin = " << begin << ", end = " << end << ", tmp_result = " << tmp_result << std::endl;
            }
            if (tmp_result.size() < result.size()) {
                result = tmp_result;
            }
        }
        if (result.size() <= s.size()) {
            return result;
        }
        return "";
    }

    /**
     * @brief 
Testcase
"acbbaca"
"aba"
Answer
"acbb"
Expected Answer
"baca"
     */

    /**
     * @brief 
     * 
     * int left = 0, right = 0; // 初始化左右边界

        while (right < s.size()) {
            // 增大窗口
            window.add(s[right]);
            right++; //移动右边界
            
            while (符合要求) {
                // 缩小窗口
                window.remove(s[left]);
                left++; //移动左边界
            }
        }

class Solution {
public:
    string minWindow(string s, string t) {
        // window为窗口中的字符，need为需要凑齐的字符
        unordered_map<char, int> need, window;
        for(const auto &c : t)  ++need[c];
        int left = 0, right = 0; //初始化左右边界，左闭右开
        //每当need中有一个字符查全，count就加一
        //当count==need.size()时代表找到一个符合要求的窗口
        int count = 0; 
        int start = 0, len = INT_MAX; //分别记录最小左边界和最小窗口长度
        while(right < s.size()){
            auto c = s[right]; //字符c即将进入窗口
            ++right; // 右移窗口
            //字符进入窗口
            if(need.count(c)){//如果字符c是t中的字符
                ++window[c]; //增加计数器
                if(window[c] == need[c]) //字符c已查全
                    ++count;
            }
            //判断左侧边界是否需要收缩，注意是while循环
            while(count == need.size()){ //窗口里所有字符的个数均达到要求
                //更新子串长度
                if(right - left < len){
                    start = left; //记录最小时候的窗口左边界（后面需要输出子串）
                    len = right - left;
                }
                //字符d即将移出窗口
                auto d = s[left];
                left++; //左移窗口
                // 进行窗口内数据的一系列更新
                if(need.count(d)){ //如果刚才移出的字符刚好也是t里面的字符
                    if(window[d] == need[d])
                        --count;
                    --window[d];
                }//否则就继续增加左边界，直到窗口window的数据不再满足要求（count != need.size()）
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

     */
};
// @lc code=end

