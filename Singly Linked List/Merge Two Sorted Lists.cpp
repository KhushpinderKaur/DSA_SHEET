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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        // BRUTE FORCE
        /*  ListNode* temp1 = list1;
          ListNode* temp2 = list2;
          vector<int> v;
          while(temp1 != NULL){
              v.push_back(temp1->val);
              temp1 = temp1->next;
          }
          while(temp2 != NULL){
              v.push_back(temp2->val);
              temp2 = temp2->next;
          }
          sort(v.begin(), v.end());
          ListNode* dummy = new ListNode(-1);
          ListNode* temp = dummy;
          for(int x : v){
              temp->next = new ListNode(x);
              temp = temp->next;
          }
          return dummy->next;
          */

        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        ListNode *t1 = list1;
        ListNode *t2 = list2;
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
};