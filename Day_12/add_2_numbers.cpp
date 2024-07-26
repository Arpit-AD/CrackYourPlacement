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
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* temp = head;
        if(!l1) return l2;
        if(!l2) return l1;
        while(l1 || l2){
            int total = 0;
            if(l1) total += l1->val, l1 = l1->next;
            if(l2) total += l2->val, l2 = l2->next;;

            if(carry) total += carry, carry = 0;
            if(total > 9) carry = total/10, total = total%10;
            ListNode* newNode = new ListNode(total);
            temp->next = newNode;
            temp = temp->next;
        }
        if(carry) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }
        return head->next;
    }
};