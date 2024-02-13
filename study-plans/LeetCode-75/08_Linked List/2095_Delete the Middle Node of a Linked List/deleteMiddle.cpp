// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

// 2024-02-12
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) {
            return nullptr;
        }
        auto slow = head;
        auto prev = head;
        auto fast = head;
        while (fast and fast->next) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = slow->next;
        return head;
    }
};