/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // if (!head) return nullptr;
        // vector<ListNode*> ans;
        // ans.push_back(head);
        // ListNode* res = nullptr;
        // for (ListNode* tmp = head->next; tmp; tmp = tmp->next)
        // {
        //     ans.push_back(tmp);
        //     if (find(ans.begin(), ans.end(), tmp->next) != ans.end()) return tmp->next;
        // }
        // return nullptr;

        if (!head) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return nullptr;
    }
};