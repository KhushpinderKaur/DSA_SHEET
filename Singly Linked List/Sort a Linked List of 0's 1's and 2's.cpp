/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution
{
public:
    ListNode *sortList(ListNode *&head)
    {
        // METHOD-1(by changing the values)
        /*  ListNode* temp = head;
          int zero = 0, one = 0, two = 0;
          while(temp != NULL){
              if(temp->data == 0)   zero++;
              else if(temp->data == 1)  one++;
              else two++;
              temp = temp->next;
          }
          temp = head;
          while(zero--){
              temp->data = 0;
              temp = temp->next;
          }
          while(one--){
              temp->data = 1;
              temp = temp->next;
          }
          while(two--){
              temp->data = 2;
              temp = temp->next;
          }
          return head;
      */

        // METHOD-2(by changing the links)
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *zeroHead = new ListNode(-1);
        ListNode *oneHead = new ListNode(-1);
        ListNode *twoHead = new ListNode(-1);

        ListNode *zero = zeroHead;
        ListNode *one = oneHead;
        ListNode *two = twoHead;
        ListNode *temp = head;

        while (temp != NULL)
        {
            if (temp->data == 0)
            {
                zero->next = temp;
                zero = temp;
            }
            else if (temp->data == 1)
            {
                one->next = temp;
                one = temp;
            }
            else
            {
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }
        zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
        one->next = twoHead->next;
        two->next = NULL;
        ListNode *newHead = zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return newHead;
    }
};