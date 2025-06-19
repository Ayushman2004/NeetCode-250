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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* lag;
        short carry = 0;

        while(t1 != NULL || t2 != NULL){
            if(t1 == NULL && t2 != NULL){
                short res = t2->val + carry;

                ListNode* n = new ListNode(res%10);
                lag->next = n;

                carry = res/10;
                lag = lag->next;
                t2 = t2->next;
                continue;
            }
            else if(t2 == NULL && t1 != NULL){
                short res = t1->val + carry;
                t1->val = res%10;
                carry = res/10;
                if(t1->next == NULL) lag = t1;
                t1 = t1->next;
                continue;
            }

            short res = t1->val + t2->val + carry;
            t1->val = res%10;
            carry = res/10;
            if(t1->next == NULL) lag = t1;
            t1 = t1->next;
            t2 = t2->next;
        }

        if(carry > 0){
            ListNode* n = new ListNode(carry);
            lag->next = n;            
        }
        return l1;
    }
};
