
// 2024-02-12
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr or head->next == nullptr or head->next->next == nullptr) {
            return head;
        }

        auto odd = head;
        auto even = head->next;
        auto p = odd;
        auto q = even;
        while (p->next or q->next) {
            if (p->next and p->next->next) {
                p->next = p->next->next;
                p = p->next;
            } else {
                p->next = nullptr;
            }

            if (q->next and q->next->next) {
                q->next = q->next->next;
                q = q->next;
            } else {
                q->next = nullptr;
            }
        }
        p->next = even;
        return head;
    }
};
