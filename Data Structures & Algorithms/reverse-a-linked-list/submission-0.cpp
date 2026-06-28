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
    ListNode* reverseList(ListNode* head) {

        ListNode* ppre=NULL;
        ListNode* pnext=NULL;
        ListNode* current=head;
        while(current!=NULL)
        {
            pnext=current->next;
            current->next=ppre;
            ppre=current;
            current=pnext;
        }
        return ppre;
        
    }
};
