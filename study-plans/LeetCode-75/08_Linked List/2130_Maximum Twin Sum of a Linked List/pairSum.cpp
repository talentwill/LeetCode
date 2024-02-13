// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list
// 2024-02-12
class Solution {
public:
    ListNode* split(ListNode* head) {
        auto slow = head;
        auto fast = head;
        while (fast and fast->next and fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto middle = slow->next;
        slow->next = nullptr;
        return middle;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            auto tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    int pairSum(ListNode* head) {
        auto second = reverse(split(head));
        int ans = 0;
        while (head != nullptr) {
            ans = max(head->val + second->val, ans);
            head = head->next;
            second = second->next;
        }
        return ans;
    }
};