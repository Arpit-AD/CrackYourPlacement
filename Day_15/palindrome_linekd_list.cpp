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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* curr = head;
        while(curr)
        {
            curr = curr->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow->next = reverse(slow->next);
        
        slow = slow->next;
        fast = head;
        while(slow){
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
        
        
    }
};