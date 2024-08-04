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
    int getDecimalValue(ListNode* head) {
        string s = "";
        int ans = 0;
        while(head != NULL)
        {
            s += to_string(head->val);
            head = head->next;
        }
        reverse(s.begin(),s.end());
        for(int i = 0; i < s.size(); i++)
        {
            ans += (s[i]-'0')*(pow(2,i));
        }
        
        return ans;

}
};