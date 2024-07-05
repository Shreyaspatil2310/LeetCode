
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    vector<int> a;
    ListNode *prev=head;
    head=head->next;
    int x=-1,y=-1, mi=1e9,r=0,i=1;
    while(head->next){
        if((prev->val < head->val and head->val > head->next->val) ||( prev->val > head->val and head->val < head->next->val)){
            if(x==-1){ 
                x=i;
                r=i;
            } else if(y==-1){
                y=i;
                mi=min(mi,y-x);
            } else {
                x=y;
                y=i;
                mi=min(mi,y-x);
            }
        }
        prev=head;
        head=head->next;
        i++;
    }
    if(y==-1){
        return {-1,-1};
    } 
    return {mi,y-r};   
    }
};