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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     
        ListNode *head=NULL;
        int sum=0;
        int carry=0;
        ListNode *ptr=head;
        
        while(l1 && l2)
        {
            sum=(l1->val + l2->val + carry)%10;
            carry=(l1->val + l2->val + carry)/10;
            if(ptr)
            {
               ListNode *x = new ListNode(sum);
                ptr->next=x;
                ptr=x;
            }
            else
            {
               cout << "adding head" << endl;
               ListNode *x = new ListNode(sum);
               head=ptr=x;
            }
                
            l1=l1->next;
            l2=l2->next;
            

        }
        
        if(l2) l1=l2;
        while(l1)
        {
            sum=(l1->val + carry)%10;
            carry=(l1->val + carry)/10;
            ptr->next=new ListNode(sum);
            ptr=ptr->next;
            l1=l1->next;
        }
        if(carry)
        {
            ptr->next=new ListNode(carry);
            
        }
        return head;
    }
};
