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
        while(temp) {
            Node * nextNode = temp->next;
            temp->next =  new Node(temp->val);
            temp->next->next = nextNode;
            temp = nextNode;
        }
        
        temp = head;
        while(temp) {
            if(temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;           
        }
        
        Node* res = new Node(0);
        Node* ans = res;
        temp = head;
        while(temp) {
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }
        
        return ans->next;
    }
};