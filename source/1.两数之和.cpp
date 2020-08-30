/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            int left = target - nums[i];
            if (hash.count(left)) {
                return {hash[left], i};
            } else {
                hash[nums[i]] = i;
            }
        }

        return {0, 0};
    }
};
// @lc code=end

