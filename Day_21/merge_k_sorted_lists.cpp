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
    ListNode* merge2Lists(ListNode* head1, ListNode* head2){
        if(!head1) return head2;
        if(!head2) return head1;

        ListNode* head = new ListNode();
        ListNode* temp = head;
        while(head1 && head2){
            if(head1->val < head2->val){
                temp->next = head1;
                head1 = head1->next;
                temp = temp->next;
            }
            else {
                temp->next = head2;
                head2 = head2->next;
                temp = temp->next;
            }
        }

        if(head1) temp->next = head1;
        if(head2) temp->next = head2;

        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];

        ListNode* resNode = merge2Lists(lists[0], lists[1]);

        for(int i = 2; i < lists.size(); i++){
            resNode = merge2Lists(resNode, lists[i]);
        }        

        return resNode;
    }
};