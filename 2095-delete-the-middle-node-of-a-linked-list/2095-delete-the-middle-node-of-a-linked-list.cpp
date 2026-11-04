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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;

        unsigned int numNode = 0;
        for (ListNode* cur = head; cur != nullptr; cur = cur->next){
            numNode++;
        }

        int end = numNode / 2;

        ListNode* cur = head;
        for(int i = 1; i < end; i++){
            cur = cur->next;
        }

        ListNode *mid = cur->next;
        cur->next = cur->next->next;

        delete mid;

        return head;
        }
};