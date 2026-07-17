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
    /* ListNode* findCollision(ListNode* A, ListNode* B, int d){
         while(d){  //let's say second one is bigger
            d--;
            B = B->next;
         }
         while(A != B){
             A = A->next;
             B = B->next;
         }
         return A;
     }
     */

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // METHOD-1
        /* ListNode* temp = headA;
         unordered_map<ListNode*, int> mp;
         while(temp != NULL){
            mp[temp] = 1;
            temp = temp->next;
         }
         temp = headB;
         while(temp != NULL){
            if(mp.find(temp) != mp.end()){
                return temp;
            }
            temp = temp->next;
         }
         return NULL;
        }
        */

        // METHOD-2
        /*  ListNode* t1 = headA;
          int n1 = 0;
          while(t1 != NULL){
              n1++;
              t1 = t1->next;
          }
          ListNode* t2 = headB;
          int n2 = 0;
          while(t2 != NULL){
              n2++;
              t2 = t2->next;
          }
          if(n1 < n2){
              return findCollision(headA, headB, n2-n1);
          }else{
              return findCollision(headB, headA, n1-n2);
          }
          return NULL;
          */

        // METHOD-3
        ListNode *t1 = headA;
        ListNode *t2 = headB;
        while (t1 != t2)
        {
            t1 = t1->next;
            t2 = t2->next;
            if (t1 == t2)
                return t1;
            if (t1 == NULL)
                t1 = headB;
            if (t2 == NULL)
                t2 = headA;
        }
        return t1;
    }
};