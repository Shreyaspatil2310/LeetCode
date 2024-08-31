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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* head1=head;

        //Find length of the linked list
        while(head!=NULL)
        {
            n++;
            head=head->next;
        }

        //Store result in ans
        vector<ListNode*> ans;

        //Find length of each list to be stored in ans
        int len=n/k;
        int rem=n%k;
        head=head1;

        for(int i=0;i<k;i++)
        {
            if(!head)
            {
                ans.push_back(NULL);
                continue;
            }
            int j=0;

            ans.push_back(head);
            
            //Add extra elements to the list rem times
            int rem1=rem>0?1:0;
            
            while(j<len+rem1-1)
            {   
                head=head->next;
                j++;
            }
            rem--;
            head1=head->next;
            head->next=NULL;
            head=head1;
        }
        return ans;
    }
};