/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */
#include "cpp_includes.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        auto odd = head;
        auto even = head->next;
        auto evenHead = head->next;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next= odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        
        return head;
    }
};
// @lc code=end

