#include <stack>

/*class ListNode
{
public:
    int data;
    ListNode *prev;
    ListNode *next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};
*/

class Solution
{
public:
    ListNode *reverseDLL(ListNode *head)
    {

        // STACK (Two-Pass) SOLUTION 
        /*
        stack<int> st;
        ListNode* temp = head;

        while (temp != NULL) {
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL) {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
        */

        
        // OPTIMAL SOLUTION
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *curr = head;
        ListNode *temp = NULL;

        while (curr != NULL)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev;
        }

        return temp->prev;
    }
};