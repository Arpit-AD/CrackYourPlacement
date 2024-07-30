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
    ListNode* mergeSortedLL(ListNode* list1, ListNode* list2){
        
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                temp->next = list1;
                list1 = list1-> next;
                temp = temp->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2-> next;
                temp = temp->next;
            }
        }
        if(list1)
        {
            temp->next = list1;
        }
        if(list2){
            temp->next = list2;
        }
        
        return head->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondPart = slow->next;
        slow->next = NULL;
        ListNode* firstPart = head;

        ListNode* sorted_secondPart = sortList(secondPart);
        ListNode* sorted_firstPart = sortList(firstPart);

        return mergeSortedLL(sorted_secondPart, sorted_firstPart);
    }
};