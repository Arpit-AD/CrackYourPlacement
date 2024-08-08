/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* appendList(Node* l1, Node* l2){
        Node* head = l1;
        Node* node = l1;
        while(node && node->next){
            node = node->next;
        }

        node->next = l2;
        if(l2){
            l2 ->prev = node;
        }

        return head;
    }
    Node* flatten(Node* head) {          
        if(!head) return head;
        Node* temp = head;
        
        while(temp->next && !temp->child){
            temp = temp->next;
        }

        if(temp->child){
            Node* forward = temp->next;
            Node* child = flatten(temp->child);
            temp->child = NULL;
            Node* list = appendList(child, forward);
            temp->next = list;
            list->prev = temp;
            return head;
        }

        return head;
    }
};