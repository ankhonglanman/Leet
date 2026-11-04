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
    int pairSum(ListNode* head) {
        vector<int> array;
        array.reserve(100000);
        for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
            array.push_back(cur->val);
        }

        int len = array.size();
        int mid = len / 2;
        int maxPairSum = INT_MIN;
        for (int i = 0; i < mid; i++) {
            int sum = array[i] + array[len - 1 - i];
            if (sum > maxPairSum) maxPairSum = sum;  
        }

        return maxPairSum;
    }
};