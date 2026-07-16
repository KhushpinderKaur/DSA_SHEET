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
    ListNode *mergeSortList(ListNode *list1, ListNode *list2)
    {
        ListNode *t1 = list1;
        ListNode *t2 = list2;
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        while (t1 != NULL && t2 != NULL)
        {
            if (t1->val < t2->val)
            {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else
            {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        if (t1)
            temp->next = t1;
        else
            temp->next = t2;
        return dummy->next;
    }

public:
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                break;
            }
        }
        return slow;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        // METHOD-1
        /* if(head == NULL || head->next == NULL){
          return head;
         }
         ListNode* temp = head;
         vector<int> arr;
         while(temp != NULL){
           arr.push_back(temp->val);
           temp = temp->next;
         }
         sort(arr.begin(), arr.end());
         temp = head;
         int i = 0;
         while(temp != NULL){
              temp->val = arr[i++];
              temp = temp->next;
         }
         return head;
         */

        // OPTIMIZED SOLUTION
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *middle = findMiddle(head);
        ListNode *right = middle->next;
        middle->next = nullptr;
        ListNode *left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeSortList(left, right);
    }
};