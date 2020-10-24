/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insert(ListNode *pos, int data) {
        ListNode* node = new ListNode(data);
        if (pos == NULL)
            return node;

        pos->next = node;
        return node;
    }

    void freeList(ListNode* l) {
        if (l != NULL)
            freeList(l->next);

        delete l;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = NULL, * tail = NULL;

        while (1) {
            if (l1 == NULL || l2 == NULL) {
                break;
            }

            int c = l1->val + l2->val + carry;
            if (c >= 10) {
                c -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }

            tail = insert(tail, c);
            if (head == NULL)
                head = tail;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL) {
            int c = l1->val + carry;
            if (c >= 10) {
                c -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }

            tail = insert(tail, c);
            if (head == NULL)
                head = tail;
            
            l1 = l1->next;
        }

        while (l2 != NULL) {
            int c = l2->val + carry;
            if (c >= 10) {
                c -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }

            tail = insert(tail, c);
            if (head == NULL)
                head = tail;
            
            l2 = l2->next;
        }

        if (carry > 0) {
            tail = insert(tail, 1);
            if (head == NULL)
                head = tail;

        }

        return head;

    }
};
// @lc code=end

