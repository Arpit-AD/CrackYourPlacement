//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* mergeLL(Node* list1, Node* list2){
        if(!list1) return list2;
        if(!list2) return list1;
        
        Node* l1 = list1;
        Node* l2 = list2;
        Node* head = new Node(0);
        Node* temp = head;
        while(l1 && l2){
            if(l1->data < l2->data){
                temp->bottom = l1;
                l1 = l1->bottom;
                temp = temp->bottom;
            }
            else{
                temp->bottom = l2;
                l2 = l2->bottom;
                temp = temp->bottom;
            }
        }
        
        if(l1) {
            while(l1){
                temp->bottom = l1;
                temp = temp->bottom;
                l1 = l1->bottom;
            }
        }
        if(l2) {
             while(l2){
                temp->bottom = l2;
                temp = temp->bottom;
                l2 = l2->bottom;
            }
        }
        
        return head->bottom;
    }
    
    Node *flatten(Node *root) {
        // Your code here
        Node* temp = root;
        Node* head = new Node(0);
        Node* res = head;
        while(temp){
            res->bottom = mergeLL(head->bottom, temp);
            temp = temp->next;
        }
        
        Node* newHead = new Node(0);
        temp = newHead;
        res = head->bottom;
        while(res){
            temp->next = res;
            res = res->bottom;
            temp = temp->next;
        }
        
        return newHead->next;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

// } Driver Code Ends