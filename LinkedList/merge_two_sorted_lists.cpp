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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == NULL && list2 == NULL) return NULL;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* fir = list1;
        ListNode* sec = list2;
        ListNode* head;
        ListNode* tail;

        if(fir->val > sec->val){
            	head = sec;
                tail = sec;
                sec = sec->next;
        }
        else{
            head = fir;
            tail = fir;
            fir = fir->next;
        }

        while(fir != NULL && sec!= NULL){
            if(fir->val > sec->val){
                tail->next = sec;
                tail = tail->next;
                sec = sec->next;
            }
            else{
                tail->next = fir;
                tail = tail->next;
                fir = fir->next;
            }
        }
        
        if(fir == NULL) tail->next = sec;
        else tail->next = fir;

        return head;
    }
};
