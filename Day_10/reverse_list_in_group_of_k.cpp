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
    ListNode* reverse(ListNode*head){
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* temp = head;
        
        while(temp)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        
        return prev;        
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 0 || k == 1 || !head || !head->next) return head;

        ListNode* temp = head;
        ListNode* temp_tail = head;

        int x = 1;
        while(x != k){
            if(temp->next == NULL || temp == NULL)
                break;
            temp = temp->next;
            x++;
        }

        if(x == k){
            temp_tail = temp-> next;
            temp->next = NULL;
            head = reverse(head);
            ListNode* temp2 = head;
            while(temp2->next){
                temp2 = temp2->next;
            }

            temp2->next = reverseKGroup(temp_tail, k);
        }        

        return head;
    }
};/**
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
    ListNode* reverse(ListNode*head){
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* temp = head;
        
        while(temp)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        
        return prev;        
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 0 || k == 1 || !head || !head->next) return head;

        ListNode* temp = head;
        ListNode* temp_tail = head;

        int x = 1;
        while(x != k){
            if(temp->next == NULL || temp == NULL)
                break;
            temp = temp->next;
            x++;
        }

        if(x == k){
            temp_tail = temp-> next;
            temp->next = NULL;
            head = reverse(head);
            ListNode* temp2 = head;
            while(temp2->next){
                temp2 = temp2->next;
            }

            temp2->next = reverseKGroup(temp_tail, k);
        }        

        return head;
    }
};