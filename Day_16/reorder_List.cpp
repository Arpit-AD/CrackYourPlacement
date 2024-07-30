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
    ListNode* reverse(ListNode* head) {
        // If the list is empty or has only one node, return the head
        if (head == nullptr || head->next == nullptr)
            return head;
        
        // Initialize pointers for reversing
        ListNode* prev = nullptr; // Previous node
        ListNode* temp = head;    // Current node
        
        // Traverse through the list and reverse pointers
        while (temp != nullptr) {
            ListNode* front = temp->next; // Store next node
            temp->next = prev;            // Reverse pointer
            prev = temp;                  // Move pointers forward
            temp = front;
        }
        
        // Return the new head of the reversed list
        return prev; // Return prev instead of head as it's now the new head
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }        

        ListNode* second = reverse(slow->next);
        slow->next = NULL;
        ListNode* first = head;

        while(second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }

    }
};