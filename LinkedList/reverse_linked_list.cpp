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
    ListNode* reverseList(ListNode* head) {

        ListNode* fir = NULL;
        ListNode* sec = head;
        if(sec == NULL) return sec;
        ListNode* thi = head->next;

        while(thi != NULL){
            sec->next = fir;
            fir = sec;
            sec = thi;
            thi = thi->next;
        }
        sec->next = fir;
        return sec;
    }
};
