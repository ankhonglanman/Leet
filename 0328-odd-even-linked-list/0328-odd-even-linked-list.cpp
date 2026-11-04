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
#define TOGGLE(x) (x) ^= true;
class Solution {
private: 
    ListNode* oddHead = nullptr;
    ListNode* evenHead = nullptr;
    ListNode* curOdd = nullptr;
    ListNode* curEven = nullptr;
    bool isOdd = true;
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;

        oddHead = head;
        evenHead = head->next;
        curOdd = oddHead;
        curEven = evenHead;

        for (ListNode* cur = evenHead->next; cur != nullptr; cur = cur->next) {
            if (isOdd) {
                curOdd->next = cur;
                curOdd = curOdd->next;
            }
            else {
                curEven->next = cur;
                curEven = curEven->next;
            }
            TOGGLE(isOdd);
        }

        curOdd->next = evenHead;
        curEven->next = nullptr;

        head = oddHead;

        return head;
    }
};