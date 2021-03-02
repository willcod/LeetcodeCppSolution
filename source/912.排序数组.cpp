/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }
    void quicksort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int pos = randomized_partition(nums, l, r);
            quicksort(nums, l, pos - 1);
            quicksort(nums, pos + 1, r);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};
// @lc code=end

