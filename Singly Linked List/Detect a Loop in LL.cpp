/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // METHOD-1 (using hashmap)
        /* ListNode* temp = head;
         unordered_map<ListNode*, int> mp;
         while(temp != NULL){
             if(mp.find(temp) != mp.end()){
                 return true;
             }
             mp[temp] = 1;
             temp = temp->next;
         }
         return false;
         */



        // METHOD-2 (using set)
        /*unordered_set<ListNode*> st;
        while(head != NULL){
            if(st.find(head) != st.end()){
                return true;
            }
            st.insert(head);
            head = head->next;
        }
        return false;
        */


        
        // METHOD-3 (using Tortoise and Hare method)
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};