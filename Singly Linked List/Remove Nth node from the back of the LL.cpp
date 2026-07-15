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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        // BRUTE FORCE
        /*  int count = 0;
          ListNode* temp = head;
          while(temp != NULL){
             count++;
             temp = temp->next;
          }
          if(count == n){
             ListNode* newHead = head->next;
             delete head;
             return newHead;
          }
          int ans = count - n;
          temp = head;
          while(temp != NULL){
             ans--;
             if(ans == 0){
                break;
             }
             temp = temp->next;
          }
          ListNode* del = temp->next;
          temp->next = temp->next->next;
          delete del;
          return head;
          */

        // OPTIMIZED SOLUTION
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        if (fast == NULL)
        {
            return head->next;
        }
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *del = slow->next;
        slow->next = slow->slow->next;
        delete del;
        return head;
    }
};