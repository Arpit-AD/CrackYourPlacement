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
        stack<int> st1, st2;
        ListNode* temp = l1;

        while(temp){
            st1.push(temp->val);
            temp = temp->next;
        }

        temp = l2;
        while(temp){
            st2.push(temp->val);
            temp = temp->next;
        }

        int carry = 0;
        vector<int> res;
        while(!st1.empty() || !st2.empty()){
            int total = 0;
            if(!st1.empty()){
                total += st1.top();
                st1.pop();
            }
            if(!st2.empty()){
                total += st2.top();
                st2.pop();
            }
            if(carry){
                total += carry;
                carry = 0;
            }
            if(total > 9){
                carry = total/10;
                total = total % 10;
            }

            res.push_back(total);
        }

        if(carry) res.push_back(carry);
        reverse(res.begin(), res.end());
        ListNode* head = new ListNode(res[0]);
        temp = head;

        for(int i = 1; i < res.size(); i++){
            ListNode* newNode = new ListNode(res[i]);
            temp->next = newNode;
            temp = temp->next;
        }

        return head;
    }
};