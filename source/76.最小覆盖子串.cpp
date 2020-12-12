/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        int required = t.length();
        vector<int> remain(128, 0);
        for (auto c : t) {
            remain[c]++;
        }

        int minlen = INT_MAX;
        int start = 0, end = 0, begin = 0;

        while (end <= s.length() && start < s.length()) {
            if (required) {
                if (end == s.length()) break;
                if (--remain[s[end]] >= 0) required--;
                end++;
            } else {
                if (end - start < minlen) {
                    minlen = end - start;
                    begin = start;
                }

                if (++remain[s[start]] > 0) required++;
                start++;
            }
        }

        return minlen == INT_MAX ? "" : s.substr(begin, minlen);
    }
};
// @lc code=end

