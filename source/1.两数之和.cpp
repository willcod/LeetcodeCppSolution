/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.count(target - nums[i]))
                return {hash[target-nums[i]], i};
            hash[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

