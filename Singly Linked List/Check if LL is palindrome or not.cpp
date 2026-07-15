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
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        // METHOD-1 (using stack)
        /* ListNode* temp = head;
         stack<int> st;
         while(temp != NULL){
             st.push(temp->val);
             temp = temp->next;
         }
         temp = head;
         while(temp != NULL){
             if(temp->val != st.top()){
                 return false;
             }
             st.pop();
             temp = temp->next;
         }
         return true;
         */

        // METHOD-2
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newHead = reverseList(slow->next);
        ListNode *first = head;
        ListNode *second = newHead;
        while (second != NULL)
        {
            if (second->val != first->val)
            {
                reverseList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseList(newHead);
        return true;
    }
};