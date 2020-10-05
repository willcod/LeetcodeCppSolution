/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector f(m + 1, vector(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            f[i][0] = i;
        }

        for (int i = 0; i <= n; i++) {
            f[0][i] = i;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] =
                        min({f[i - 1][j - 1], f[i - 1][j], f[i][j - 1]}) + 1;
                }
            }
        }

        return f[m][n];
    }
};
// @lc code=end
