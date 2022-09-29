/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (54.78%)
 * Likes:    1015
 * Dislikes: 0
 * Total Accepted:    232.1K
 * Total Submissions: 423.6K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 * 
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 * 
 * 
 */

/**
 * class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();

        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);
        for (int i = 0; i < pLen; ++i) {
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }

        if (sCount == pCount) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i) {
            --sCount[s[i] - 'a'];
            ++sCount[s[i + pLen] - 'a'];

            if (sCount == pCount) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/find-all-anagrams-in-a-string/solution/zhao-dao-zi-fu-chuan-zhong-suo-you-zi-mu-xzin/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 * 
 */
// @lc code=start
class Solution {
public:
    vector<int> findAnagrams0(string s, string p) {
        vector<int> result;
        if (p.empty() || s.size() < p.size()) {
            return result;
        }
        unordered_map<char, int> mapping;
        for (auto ch : p) {
            ++mapping[ch];
        }
        for (int i = 0; i <= s.size() - p.size(); ++i) {
            unordered_map<char, int> tmp = mapping;
            for (int j = 0; j < p.size(); ++j) {
                if (tmp.count(s[i + j]) > 0) {
                    --tmp[s[i + j]];
                    if (tmp[s[i + j]] == 0) {
                        tmp.erase(s[i + j]);
                    }
                }
            }
            if (tmp.size() == 0) {
                result.push_back(i);
            }
        }
        return result;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (p.empty() || s.size() < p.size()) {
            return result;
        }
        array<int, 26> need{};
        for (auto ch : p) {
            ++need[ch - 'a'];
        }
        int left = 0, right = 0;
        int count = 0;                          // 匹配的元素个数
        while (right < s.size()) {
            if (need[s[right] - 'a'] > 0) {
                ++count;
            }
            --need[s[right++] - 'a'];           // 更新了right值

            while (count == p.size()) {
                if (count == right - left) {
                    result.push_back(left);
                }
                // result.push_back(left);
                if (need[s[left] - 'a'] == 0) {
                    --count;
                }
                ++need[s[left] - 'a'];
                ++left;
            }
        }
        return result;
    }
};
// @lc code=end

