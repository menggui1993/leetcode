# 002 Add Two numbers

Difficulty: Medium

## 1. Problem Statement

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Example:
> Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)  
> Output: 7 -> 0 -> 8

## 2. Method

Keep an overflow, add until at least one of the list run out. Append the remaining list. Don't forget the final overflow.

## 3. Code

```c++
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rl = new ListNode(0);
        ListNode* l3 = rl;
        ListNode* pl = l3;
        int of = 0;
        while (l1 && l2){
            l3->val = (l1->val + l2->val + of) % 10;
            of = (l1->val + l2->val + of) / 10;
            l1 = l1->next;
            l2 = l2->next;
            l3->next = new ListNode(0);
            pl = l3;
            l3 = l3->next;
        }
        while (l1){
            l3->val = (l1->val + of) % 10;
            of = (l1->val + of) / 10;
            l1 = l1->next;
            l3->next = new ListNode(0);
            pl = l3;
            l3 = l3->next;
        }
        while (l2){
            l3->val = (l2->val + of) % 10;
            of = (l2->val + of) / 10;
            l2 = l2->next;
            l3->next = new ListNode(0);
            pl = l3;
            l3 = l3->next;
        }
        if (of == 1)
            l3->val = 1;
        else{
            delete l3;
            if (pl)
                pl->next = NULL;
        }

        return rl;
    }
};
```
