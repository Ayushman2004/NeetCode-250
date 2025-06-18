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
    void reorderList(ListNode* head) {

        vector<ListNode*> vec;
        while(head != NULL){
            vec.push_back(head);
            head = head->next;
        }

        head = vec[0];
        ListNode* temp = head;
        bool flag = true;
        while(vec.size()>1){
            if(flag){
                temp->next = vec[vec.size()-1];
                temp = temp->next;
                vec.erase(vec.begin());
                flag = false;
            }
            else{
                temp->next = vec[0];
                temp = temp->next;
                vec.pop_back();
                flag = true;
            }
        }
        temp->next = NULL;
    }
};
