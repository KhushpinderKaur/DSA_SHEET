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
    int findLength(ListNode *slow)
    {
        int count = 1;
        ListNode *temp = slow->next;
        while (temp != slow)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

public:
    int findLengthOfLoop(ListNode *head)
    {
        // METHOD 1
        /*if(head == NULL || head->next == NULL){
            return 0;
        }
        ListNode* temp = head;
        unordered_map<ListNode*, int> mp;
        int count = 1;
        while(temp != NULL){
            if(mp.find(temp) != mp.end()){
                return count - mp[temp];
            }
            mp[temp] = count;
            count++;
            temp = temp->next;
        }
        return 0;
        */

        

        // METHOD-2
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return findLength(slow);
            }
        }
        return 0;
    }
};