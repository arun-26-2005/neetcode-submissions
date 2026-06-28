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
         ListNode* temp1=l1;
         
         ListNode* temp2=l2;
         ListNode* ppre=NULL;
         int cy=0;
        
         while(temp1!=NULL && temp2!=NULL)
         {
                int b=temp1->val+temp2->val+cy;
                
                if(b<=9)
                {
                    temp1->val=b;
                    cy=0;
                }
                else
                {
                    temp1->val=(b%10);
                    cy=b/10;
                    
                }
                ppre=temp1;
                temp1=temp1->next;
                temp2=temp2->next;
         }
         while(temp1!=NULL)
         {
            int c=cy+temp1->val;
            
                if(c<=9)
                {
                    temp1->val=c;
                    cy=0;
                }
                else
                {
                    cy=c/10;
                   temp1->val=(c%10);
                }
                ppre=temp1;
                temp1=temp1->next;
         }
         while(temp2!=NULL)
         {
                int b=cy+temp2->val;
                ListNode* pnew=new ListNode();
            
                if(b<=9)
                {
                   pnew->val=(b);
                    cy=0;
                }
                else
                {
                    cy=b/10;
                    pnew->val=(b%10);
                }
                ppre->next=pnew;
                ppre=ppre->next;
                temp2=temp2->next;
         }
         if(cy!=0)
         {
            ListNode* pnew=new ListNode();
           pnew->val=(cy);
           
           ppre->next=pnew;
         }
        return l1;
    }

};