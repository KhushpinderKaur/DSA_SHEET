/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution
{
public:
    ListNode *middleOfLinkedList(ListNode *head)
    {

        // NAIVE SOLUTION
        /*     ListNode* temp = head;
              int count = 0;
              while(temp != NULL){
                 count++;
                 temp = temp->next;
              }
              temp = head;
              int mid = (count/2)+1;
              while(temp != NULL){
                 mid = mid - 1;
                 if(mid == 0){
                     break;
                 }
                 temp = temp->next;
              }
           return temp;
        */

        // TORTOISE AND HARE METHOD
        ListNode* slow = head;
        ListNode* fast = head;
        // I can move two steps only if both the current node and the next node exist.
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};