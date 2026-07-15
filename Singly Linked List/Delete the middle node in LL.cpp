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
    ListNode *deleteMiddle(ListNode *head)
    {

        // BRUTE FORCE
        /*if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        int stop = count/2;
        temp = head;
        while(temp != NULL){
            stop--;
            if(stop == 0){
                break;
            }
            temp = temp->next;
        }
        ListNode* mid = temp->next;
        temp->next = temp->next->next;
        delete mid;
        return head;
        */

        // OPTIMAL SOLUTION
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next->next != NULL && fast->next->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = slow->next->next;
        delete mid;
        return head;
    }
};