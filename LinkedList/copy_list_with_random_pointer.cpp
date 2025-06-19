/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* temp = head;
        Node h(0);
        Node* p = &h;
        unordered_map<Node*, Node*> map;

        while(temp != NULL){
            Node* n = new Node(temp->val);
            p->next = n;
            map[temp] = n;
            
            p = p->next;
            temp = temp->next;
        }

        p = &h;
        temp = head;
        p = p->next;
        while(p != NULL){
            if(temp->random == NULL) p->random = NULL;
            else p->random = map[temp->random];

            p = p->next;
            temp = temp->next;
        }
        return h.next;
    }
};
