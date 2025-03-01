class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* start = new ListNode(-1);
        start->next = head;
        ListNode* cur = head;
        ListNode* prev = start;

        while (cur) {
            if (cur->next && cur->next->val < cur->val) {
                while (prev->next && prev->next->val < cur->next->val) {
                    prev = prev->next;
                }
                ListNode* temp = prev->next;
                prev->next = cur->next;
                cur->next = cur->next->next;
                prev->next->next = temp;

                prev = start;
            } else {
                cur = cur->next;
            }
        }
        return start->next;
    }
};